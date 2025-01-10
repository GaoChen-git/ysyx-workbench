#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static int print_char(char **out, size_t *remaining, char ch) {
  if (*out) {
    if (*remaining > 1) {
      **out = ch;
      (*out)++;
      (*remaining)--;
    } else {
      return -1; // Buffer overflow
    }
  } else {
    putch(ch);
  }
  return 1;
}

static int print_string(char **out, size_t *remaining, const char *str) {
  int count = 0;
  while (*str) {
    if (print_char(out, remaining, *str++) == -1) return -1;
    count++;
  }
  return count;
}

static int print_integer(char **out, size_t *remaining, int num, int width, char pad) {
    char buffer[12]; // Enough to hold -2^31 to 2^31-1
    int i = 0, len = 0;

    if (num < 0) {
        if (print_char(out, remaining, '-') == -1) return -1;
        num = -num;
        width--; // Account for the '-' sign
    }

    do {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    } while (num > 0);

    len = i;
    while (len < width) { // Pad with the specified character
        if (print_char(out, remaining, pad) == -1) return -1;
        len++;
    }

    for (i--; i >= 0; i--) {
        if (print_char(out, remaining, buffer[i]) == -1) return -1;
    }

    return 0;
}

static int vformat(char *out, size_t n, const char *fmt, va_list ap) {
  char *output = out;
  size_t remaining = n;
  int count = 0;

  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      char pad = ' ';  // Default padding
      int width = 0;

      if (*fmt == '0') { // Zero padding
        pad = '0';
        fmt++;
      }

      while (*fmt >= '0' && *fmt <= '9') { // Parse width
        width = width * 10 + (*fmt - '0');
        fmt++;
      }

      if (*fmt == 'd') {
        int val = va_arg(ap, int);
        if (print_integer(&output, &remaining, val, width, pad) == -1) return -1;
      } else if (*fmt == 's') {
        const char *val = va_arg(ap, const char *);
        if (print_string(&output, &remaining, val) == -1) return -1;
      } else if (*fmt == 'c') {
        char val = (char)va_arg(ap, int);
        if (print_char(&output, &remaining, val) == -1) return -1;
      } else {
        return -1; // Unsupported format specifier
      }
      fmt++;
    } else {
      if (print_char(&output, &remaining, *fmt++) == -1) return -1;
    }
  }

  if (output && n > 0) {
    *output = '\0';
  }

  return count;
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int result = vformat(NULL, 0, fmt, ap);
  va_end(ap);
  return result;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vformat(out, SIZE_MAX, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int result = vformat(out, SIZE_MAX, fmt, ap);
  va_end(ap);
  return result;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int result = vformat(out, n, fmt, ap);
  va_end(ap);
  return result;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  return vformat(out, n, fmt, ap);
}

#endif

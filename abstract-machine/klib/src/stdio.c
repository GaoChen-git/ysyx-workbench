#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// Helper function to output formatted text
static int vsnprintf_helper(char *out, size_t n, const char *fmt, va_list ap) {
  size_t written = 0;
  const char *p = fmt;
  char buffer[32];

  while (*p) {
    if (*p == '%') {
      p++;
      switch (*p) {
        case 'd': {
          int val = va_arg(ap, int);
          int len = snprintf(buffer, sizeof(buffer), "%d", val);
          for (int i = 0; i < len && written < n - 1; i++) {
            out[written++] = buffer[i];
          }
          break;
        }
        case 's': {
          const char *str = va_arg(ap, const char *);
          while (*str && written < n - 1) {
            out[written++] = *str++;
          }
          break;
        }
        case 'c': {
          char ch = (char)va_arg(ap, int);
          if (written < n - 1) {
            out[written++] = ch;
          }
          break;
        }
        case '%': {
          if (written < n - 1) {
            out[written++] = '%';
          }
          break;
        }
        default: {
          // Unsupported format specifier
          break;
        }
      }
    } else {
      if (written < n - 1) {
        out[written++] = *p;
      }
    }
    p++;
  }
  if (n > 0) {
    out[written] = '\0';
  }
  return written;
}

int printf(const char *fmt, ...) {
  char buffer[256];
  va_list ap;
  va_start(ap, fmt);
  int written = vsnprintf_helper(buffer, sizeof(buffer), fmt, ap);
  va_end(ap);
  for (int i = 0; i < written; i++) {
    putch(buffer[i]);
  }
  return written;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf_helper(out, (size_t)-1, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int written = vsnprintf_helper(out, (size_t)-1, fmt, ap);
  va_end(ap);
  return written;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int written = vsnprintf_helper(out, n, fmt, ap);
  va_end(ap);
  return written;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  return vsnprintf_helper(out, n, fmt, ap);
}

#endif

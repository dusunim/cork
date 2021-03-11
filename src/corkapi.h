#pragma once

#if defined(_USE_CORK_STATIC_)
#  define CORK_API
#else
#  if defined(_WIN32) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__)
#    if defined(_MSC_VER)
#      if defined(_USE_CORK_EXPORT)
#        define CORK_API __declspec(dllexport)
#      else
#        define CORK_API __declspec(dllimport)
#      endif
#    else
#      if defined(_USE_CORK_EXPORT)
#        define CORK_API __attribute__((dllexport))
#      else
#        define CORK_API __attribute__((dllimport))
#      endif
#    endif
#  else
#      define CORK_API __attribute__((visibility("default")))
#  endif
#endif

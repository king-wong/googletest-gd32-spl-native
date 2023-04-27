# googletest-gd32-spl-native

setting up test framework for gd32f3x0g-start and google test using platformio

This project started with the working example from https://github.com/platformio/platformio-examples/tree/develop/unit-testing/googletest

Instead of `[env:esp32dev]`, `[env:genericGD32F330C8]` and `[env:gd32350g_start]` was added.

https://github.com/king-wong/googletest-gd32-spl-native/blob/28daff8e21c54efef4d519b2fffcbddfc9fdb4f4/test/gd32_config.c was added.

In test_main.cpp, the following was added:

#ifdef GD32F3x0
/* to avoid code duplication: let's use the same .c file as in the embedded folder already. */
/* a bit hacky and makes us dependent on test_embedded existing. Copy-paste code if needed. */


#include "../gd32_config.c"

https://github.com/king-wong/googletest-gd32-spl-native/blob/28daff8e21c54efef4d519b2fffcbddfc9fdb4f4/test/test_gtest/test_main.cpp#L46-L60

The following errors were seen:

 Executing task in folder googletest-gd32-spl-native: C:\Users\kwong\.platformio\penv\Scripts\platformio.exe test --environment genericGD32F330C8 

Verbosity level can be increased via `-v, -vv, or -vvv` option
Collected 2 tests

Processing test_gmock in genericGD32F330C8 environment
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Building & Uploading...
c:\users\kwong\.platformio\packages\toolchain-gccarmnoneeabi\arm-none-eabi\include\stdio.h: In function 'putchar':
test\gd32_config.c:77:1: warning: control reaches end of non-void function [-Wreturn-type]
   77 | }
      | ^
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-string.h:56,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-filepath.h:45,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-filepath.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-port.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-typed-test.h:174,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-typed-test.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-printers.h:114,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-matchers.h:48,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-death-test-internal.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-death-test.h:43,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-death-test.cc:33:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-test-part.h:40,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-test-part.cc:33:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-message.h:55,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-assertion-result.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-assertion-result.cc:34:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-printers.h:114,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-matchers.h:48,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-matchers.cc:35:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-internal-utils.cc:36:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-actions.h:145,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-spec-builders.h:75,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-spec-builders.cc:35:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-filepath.o] Error 1
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-actions.h:145,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock.h:56,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-assertion-result.o] Error 1
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-message.h:55,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-assertion-result.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest.h:59,
                 from test\test_gmock\src\test_main.cpp:17:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-message.h:55,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-assertion-result.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest.h:59,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest.cc:33:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-cardinalities.h:47,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-cardinalities.cc:34:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-printers.h:114,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-printers.cc:43:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
.pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-port.cc: In constructor 'testing::internal::CapturedStream::CapturedStream(int)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-port.cc:1102:31: error: '::mkstemp' has not been declared
 1102 |     const int captured_fd = ::mkstemp(const_cast<char*>(name_template.data()));
      |                               ^~~~~~~
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-test-part.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-death-test.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-matchers.o] Error 1
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-matchers.h:271,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-matchers.cc:35:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-typed-test.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-port.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-spec-builders.o] Error 1
In file included from test\test_gmock\src\test_main.cpp:40:
test\test_gmock/../gd32_config.c: In function 'int putchar(int)':
test\test_gmock/../gd32_config.c:77:1: warning: no return statement in function returning non-void [-Wreturn-type]
   77 | }
      | ^
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-cardinalities.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-internal-utils.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-printers.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-matchers.o] Error 1
*** [.pio\build\genericGD32F330C8\test\test_gmock\src\test_main.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest.o] Error 1
Uploading stage has failed, see errors above. Use `pio test -vvv` option to enable verbose output.
----------------------------------------------------------------------------------------------------- genericGD32F330C8:test_gmock [ERRORED] Took 8.21 seconds -----------------------------------------------------------------------------------------------------

Processing test_gtest in genericGD32F330C8 environment
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Building & Uploading...
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-string.h:56,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-filepath.h:45,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-filepath.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-test-part.h:40,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-test-part.cc:33:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-message.h:55,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-assertion-result.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-assertion-result.cc:34:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-cardinalities.h:47,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-cardinalities.cc:34:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-matchers.h:271,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-matchers.cc:35:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-printers.h:114,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-matchers.h:48,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-death-test-internal.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-death-test.h:43,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-death-test.cc:33:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-internal-utils.cc:36:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-actions.h:145,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-spec-builders.h:75,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock-spec-builders.cc:35:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-printers.h:114,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-matchers.h:48,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-matchers.cc:35:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-filepath.o] Error 1
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-typed-test.h:174,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-typed-test.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-port.h:57,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/internal/gmock-internal-utils.h:49,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock-actions.h:145,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\include/gmock/gmock.h:56,
                 from .pio\libdeps\genericGD32F330C8\googletest\googlemock\src\gmock.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-internal.h:42,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-printers.h:114,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-printers.cc:43:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-message.h:55,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-assertion-result.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest.h:59,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest.cc:33:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-port.cc:30:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-assertion-result.o] Error 1
In file included from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-message.h:55,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest-assertion-result.h:46,
                 from .pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/gtest.h:59,
                 from test\test_gtest\test_main.cpp:17:
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'int testing::internal::posix::FileNo(FILE*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2015:40: error: 'fileno' was not declared in this scope; did you mean 'file'?
 2015 | inline int FileNo(FILE* file) { return fileno(file); }
      |                                        ^~~~~~
      |                                        file
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'char* testing::internal::posix::StrDup(const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2021:47: error: 'strdup' was not declared in this scope; did you mean 'StrDup'?
 2021 | inline char* StrDup(const char* src) { return strdup(src); }
      |                                               ^~~~~~
      |                                               StrDup
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-matchers.o] Error 1
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h: In function 'FILE* testing::internal::posix::FDOpen(int, const char*)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\include/gtest/internal/gtest-port.h:2065:56: error: 'fdopen' was not declared in this scope; did you mean 'fopen'?
 2065 | inline FILE* FDOpen(int fd, const char* mode) { return fdopen(fd, mode); }
      |                                                        ^~~~~~
      |                                                        fopen
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-death-test.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-matchers.o] Error 1
In file included from test\test_gtest\test_main.cpp:50:
test\test_gtest\../gd32_config.c: In function 'int putchar(int)':
test\test_gtest\../gd32_config.c:77:1: warning: no return statement in function returning non-void [-Wreturn-type]
   77 | }
      | ^
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-test-part.o] Error 1
.pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-port.cc: In constructor 'testing::internal::CapturedStream::CapturedStream(int)':
.pio\libdeps\genericGD32F330C8\googletest\googletest\src\gtest-port.cc:1102:31: error: '::mkstemp' has not been declared
 1102 |     const int captured_fd = ::mkstemp(const_cast<char*>(name_template.data()));
      |                               ^~~~~~~
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-cardinalities.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-printers.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-internal-utils.o] Error 1
*** [.pio\build\genericGD32F330C8\test\test_gtest\test_main.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googlemock\src\gmock-spec-builders.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-typed-test.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest-port.o] Error 1
*** [.pio\build\genericGD32F330C8\liba08\googletest\googletest\src\gtest.o] Error 1
Uploading stage has failed, see errors above. Use `pio test -vvv` option to enable verbose output.
----------------------------------------------------------------------------------------------------- genericGD32F330C8:test_gtest [ERRORED] Took 7.81 seconds -----------------------------------------------------------------------------------------------------

============================================================================================================================= SUMMARY ============================================================================================================================= 
Environment        Test        Status    Duration
-----------------  ----------  --------  ------------
genericGD32F330C8  test_gmock  ERRORED   00:00:08.210
genericGD32F330C8  test_gtest  ERRORED   00:00:07.811
============================================================================================================ 2 test cases: 0 succeeded in 00:00:16.021 ============================================================================================================ 

 *  The terminal process "C:\Users\kwong\.platformio\penv\Scripts\platformio.exe 'test', '--environment', 'genericGD32F330C8'" terminated with exit code: 1. 
 *  Terminal will be reused by tasks, press any key to close it. 




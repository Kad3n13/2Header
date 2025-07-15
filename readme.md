# 2.hHeader — Custom `<limits.h>` Constants in Pure C

| Custom Name | Standard Equivalent | Description                                       |
|-------------|---------------------|---------------------------------------------------|
| C_B         | CHAR_BIT            | Number of bits in a `char`                        |
| SC_M        | SCHAR_MIN           | Minimum value of a `signed char`                  |
| SC_MX       | SCHAR_MAX           | Maximum value of a `signed char`                  |
| US_CX       | UCHAR_MAX           | Maximum value of an `unsigned char`               |
| C_M         | CHAR_MIN            | Minimum value of `char` (implementation-defined)  |
| C_MX        | CHAR_MAX            | Maximum value of `char` (implementation-defined)  |
| MB_LM       | MB_LEN_MAX          | Max bytes in a multibyte character                |
| SH_M        | SHRT_MIN            | Minimum value of a `short`                        |
| SH_MX       | SHRT_MAX            | Maximum value of a `short`                        |
| USH_MX      | USHRT_MAX           | Maximum value of an `unsigned short`              |
| I_M         | INT_MIN             | Minimum value of an `int`                         |
| I_MX        | INT_MAX             | Maximum value of an `int`                         |
| UI_MX       | UINT_MAX            | Maximum value of an `unsigned int`                |
| L_M         | LONG_MIN            | Minimum value of a `long`                         |
| L_MX        | LONG_MAX            | Maximum value of a `long`                         |
| UL_MX       | ULONG_MAX           | Maximum value of an `unsigned long`               |

---


<p align="center">
  <img src="https://img.shields.io/badge/2Header-Custom%20limits.h-orange?style=for-the-badge&logo=c" alt="2Header Badge" />
</p>
## About

**`2.hHeader`** reimplements the core constants from `<limits.h>` using **pure C**, with no macros, no standard includes, and no external dependencies.  
All values are defined as global `const` variables with standard-conforming behavior — ideal for education, portability, and introspection.

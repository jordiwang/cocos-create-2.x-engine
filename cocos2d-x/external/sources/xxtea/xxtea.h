/***********************************************************************
 
 Copyright 2006-2009 Ma Bingyao
 Copyright 2013 Gao Chunhui, Liu Tao
 
 These sources is free software. Redistributions of source code must
 retain the above copyright notice. Redistributions in binary form
 must reproduce the above copyright notice. You can redistribute it
 freely. You can use it with any free or commercial software.
 
 These sources is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY. Without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 
 github: https://github.com/liut/pecl-xxtea
 
 *************************************************************************/

#ifndef XXTEA_H
#define XXTEA_H

#include <stddef.h> /* for size_t & NULL declarations */

#if defined(_WIN32) && defined(_WINDOWS)
#if defined(_USRDLL)
#define XXTEA_DLL     __declspec(dllexport)
#else         /* use a DLL library */
#define XXTEA_DLL     __declspec(dllimport)
#endif
#else
#define XXTEA_DLL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)

typedef unsigned __int32 xxtea_long;

#else

#if defined(__FreeBSD__) && __FreeBSD__ < 5
/* FreeBSD 4 doesn't have stdint.h file */
#include <inttypes.h>
#else
#include <stdint.h>
#endif

typedef uint32_t xxtea_long;

#endif /* end of if defined(_MSC_VER) */

#define XXTEA_MX (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (k[p & 3 ^ e] ^ z)
#define XXTEA_DELTA 0x9e3779b9

#define xxtea_encrypt ityjso_wo89342
#define xxtea_decrypt tn_484bnai3Fl3

unsigned char *xxtea_encrypt(unsigned char *data, xxtea_long data_len, unsigned char *key, xxtea_long key_len, xxtea_long *ret_length);
unsigned char *xxtea_decrypt(unsigned char *data, xxtea_long data_len, unsigned char *key, xxtea_long key_len, xxtea_long *ret_length);

#endif


#ifdef __cplusplus
}
#endif

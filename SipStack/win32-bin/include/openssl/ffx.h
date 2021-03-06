/* crypto/ffx/ffx.h */
/* ====================================================================
 * Copyright (c) 2015 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 */

#ifndef HEADER_FFX_H
#define HEADER_FFX_H

#include <string.h>
#include <openssl/aes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int flag;
	AES_KEY key;
} FFX_CTX;

int  FFX_init(FFX_CTX *ctx, int flag, const unsigned char *key, int keybits);
void FFX_cleanup(FFX_CTX *ctx);
int  FFX_encrypt(FFX_CTX *ctx, const char *in, size_t inlen,
	const unsigned char *tweak, size_t tweaklen, char *out);
int  FFX_decrypt(FFX_CTX *ctx, const char *in, size_t inlen,
	const unsigned char *tweak, size_t tweaklen, char *out);
int  FFX_compute_luhn(const char *in, size_t inlen);


/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */
void ERR_load_FFX_strings(void);

/* Error codes for the FFX functions. */

/* Function codes. */
# define FFX_F_FFX_COMPUTE_LUHN                           100
# define FFX_F_FFX_DECRYPT                                101
# define FFX_F_FFX_ENCRYPT                                102
# define FFX_F_FFX_INIT                                   103

/* Reason codes. */
# define FFX_R_INIT_KEY_FAILED                            100
# define FFX_R_INVALID_DIGITS_FORMAT                      101
# define FFX_R_INVALID_DIGITS_LENGTH                      102
# define FFX_R_INVALID_DIGIT_STRING                       103
# define FFX_R_INVALID_TWEAK_LENGTH                       104

#ifdef  __cplusplus
}
#endif
#endif

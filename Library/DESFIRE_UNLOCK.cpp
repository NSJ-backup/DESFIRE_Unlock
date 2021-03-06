// DESFIRE_UNLOCK.cpp: DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include <openssl/des.h>
#include "desfire_unlock.h"

static DES_key_schedule SchKey1, SchKey2, SchKey3;

 void triple_des_cbc_encrypt(char * input_data, char * result, int size, char * init_vector)
{
	DES_ede3_cbc_encrypt(
		(unsigned char*)input_data, 
		(unsigned char*)result,
		size,
		&SchKey1, &SchKey2, &SchKey3, 
		(DES_cblock *)init_vector, DES_ENCRYPT);
}

 void triple_des_cbc_decrypt(char * input_data, char * result, int size, char * init_vector)
{
	DES_ede3_cbc_encrypt(
		(unsigned char*)input_data,
		(unsigned char*)result,
		size,
		&SchKey1, &SchKey2, &SchKey3,
		(DES_cblock *)init_vector, DES_DECRYPT);
}

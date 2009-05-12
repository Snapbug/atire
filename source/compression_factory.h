/*
	COMPRESSION_FACTORY.H
	---------------------
*/
#ifndef __COMPRESSION_FACTORY_H__
#define __COMPRESSION_FACTORY_H__

#include <string.h>
#include "compress.h"
#include "compression_factory_scheme.h"

/*
	class ANT_COMPRESSION_FACTORY
	-----------------------------
*/
class ANT_compression_factory : ANT_compress
{
public:
	enum {	
		NONE 			=   1, 
		VARIABLE_BYTE 	=   2, 
		SIMPLE_9 		=   4, 
		RELATIVE_10 	=   8, 
		CARRYOVER_12 	=  16, 
		SIGMA 			=  32, 
		ELIAS_DELTA 	=  64, 
		ELIAS_GAMMA 	= 128, 
		GOLOMB 			= 256
		} ;
private:
	static long number_of_techniques;
	static ANT_compression_factory_scheme scheme[];
	long long failures;
	long long integers_compressed;
	unsigned long schemes_to_use;
	/*
		The validation buffer is used for checking the pre-compresson and decompressed compressed strings
		are the same, and also to measure the decompression performance.
	*/
	long validate;
	ANT_compressable_integer *validation_buffer;
	long long validation_buffer_length;
	
public:
	ANT_compression_factory();
	virtual ~ANT_compression_factory();

	virtual long long compress(unsigned char *destination, long long destination_length, ANT_compressable_integer *source, long long source_integers);
	virtual void decompress(ANT_compressable_integer *destination, unsigned char *source, long long destination_integers);

	void set_scheme(unsigned long scheme) { schemes_to_use = scheme; }
	void set_validation(long validate) { this->validate = validate; }
										
	void text_render(void);

} ;

#endif __COMPRESSION_FACTORY_H__
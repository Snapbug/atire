/*
	DIRECTORY_ITERATOR_WARC_GZ_RECURSIVE.H
	--------------------------------------
*/
#ifndef DIRECTORY_ITERATOR_TREC_GZ_RECURSIVE_H_
#define DIRECTORY_ITERATOR_TREC_GZ_RECURSIVE_H_

#include "directory_iterator.h"

class ANT_instream;
class ANT_memory;

/*
	class ANT_DIRECTORY_ITERATOR_WARC
	---------------------------------
*/
class ANT_directory_iterator_trec_gz_recursive : public ANT_directory_iterator
{
protected:
static long tid;
	char *source;
	ANT_instream *file_stream, *decompressor;
	ANT_instream *instream_buffer_a;
	ANT_instream *instream_buffer_b;
	ANT_instream *scrubber;
	ANT_directory_iterator *filename_provider;
	ANT_directory_iterator *detrecer;
	ANT_memory *memory;
	ANT_directory_iterator_object *more_files;
	long first_time;
	long long scrubbing_options;

protected:
	ANT_directory_iterator *new_provider(char *filename);

public:
	ANT_directory_iterator_trec_gz_recursive(char *source, long get_file = 0, long long scrubbing_options = 0);
	virtual ~ANT_directory_iterator_trec_gz_recursive();

	virtual ANT_directory_iterator_object *first(ANT_directory_iterator_object *object) { return next(object); }
	virtual ANT_directory_iterator_object *next(ANT_directory_iterator_object *object);
} ;

#endif /* DIRECTORY_ITERATOR_WARC_GZ_RECURSIVE_H_ */

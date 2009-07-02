/*
 * freq_file.h
 *
 *  Created on: Oct 26, 2008
 *      Author: monfee
 */

#ifndef FREQ_FILE_H_
#define FREQ_FILE_H_

#include "index_file.h"
#include "freq.h"

class FreqFile : public File {
	typedef Freq::string_type						string_type;
	typedef Freq::word_type 						word_type;
	typedef Freq::word_ptr_type						word_ptr_type;
	typedef Freq::array_type						array_type;
	typedef Freq::string_array						string_array;

public:
	static const int UNICODE_CHAR_LENGTH = IndexFile::UNICODE_CHAR_LENGTH;
	static const int RECORD_LENGTH = UNICODE_CHAR_LENGTH + sizeof(unsigned int);
	//static const std::string EXT_NAME;

private:
	Freq& 		freq_;
	IndexFile 	idxf_;
	int			wlen_;

public:
	FreqFile(std::string name, Freq& freq) :
		File::File(name), freq_(freq), idxf_(name) { init(); }
	FreqFile(std::string name, unsigned int size, Freq& freq) :
		File::File(name, size), freq_(freq), idxf_(name) { init(); }
	virtual ~FreqFile();

	void write(File::array_type& arr);
	void read();
	void read_with_index();
	unsigned int cal(File::array_type& arr);

	int wlen() { return wlen_; }
	void wlen(int len) { wlen_ = len; idxf_.wlen(len); }

private:
	void init();
};

//const std::string FreqFile::EXT_NAME = ".frq";

#endif /* FREQ_FILE_H_ */
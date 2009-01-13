/*
	STEMMER_NONE.H
	--------------
*/

#ifndef __STEMMER_NONE_H__
#define __STEMMER_NONE_H__

#include "stemmer.h"

class ANT_stemmer_none : public ANT_stemmer
{
public:
	ANT_stemmer_none(ANT_search_engine *search_engine) : ANT_stemmer(search_engine) {}
	virtual ~ANT_stemmer_none() {} 

	virtual char *first(char *term) { return ANT_btree_iterator::first(term); }
	virtual char *next(void) { return NULL; }

	virtual char *stem(char *term) { return term; }
} ;


#endif __STEMMER_NONE_H__
/*
	READABILITY.H
	-------------
*/

#ifndef READABILITY_H_
#define READABILITY_H_

#include "string_pair.h"
#include "memory_index.h"
#include "memory_index_hash_node.h"

/* 
	class ANT_READABILITY
	---------------------
*/
class ANT_readability
{
friend class ANT_readability_factory;

public:
	ANT_readability() {}
	virtual ~ANT_readability() {}
	
	virtual void index(ANT_memory_indexer *index) { index = index; /* prevent compiler warning */ }

protected:
	ANT_string_pair *measure_name;
	
	virtual long score(void) { return 0; }

	virtual void handle_token(ANT_string_pair *token) { token = token; /* prevent compiler warning */ }
	virtual void handle_node(ANT_memory_indexer_node *node) {node = node; /* prevent compiler warning */ }
} ;

#endif  /* READABILITY_H_ */

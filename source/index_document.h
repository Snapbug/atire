/*
	INDEX_DOCUMENT.H
	----------------
*/
#ifndef INDEX_DOCUMENT_H_
#define INDEX_DOCUMENT_H_

class ANT_memory_indexer;
class ANT_stem;
class ANT_readability_factory;
class ANT_directory_iterator_object;

/*
	class ANT_INDEX_DOCUMENT
	------------------------
*/
class ANT_index_document
{
public:
	virtual long index_document(ANT_memory_indexer *indexer, ANT_stem *stemmer, long segmentation, ANT_readability_factory *readability, long long doc, ANT_directory_iterator_object *current_file);
} ;

#endif /* INDEX_DOCUMENT_H_ */


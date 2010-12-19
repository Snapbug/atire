/*
	RELEVANCE_FEEDBACK.H
	--------------------
*/
#ifndef RELEVANCE_FEEDBACK_H_
#define RELEVANCE_FEEDBACK_H_

class ANT_memory;
class ANT_memory_index;
class ANT_memory_index_one;
class ANT_memory_index_one_node;
class ANT_search_engine;
class ANT_search_engine_result;
class ANT_parser;

/*
	class ANT_RELEVANCE_FEEDBACK
	----------------------------
*/
class ANT_relevance_feedback
{
protected:
	ANT_memory *memory;
	ANT_search_engine *search_engine;
	ANT_memory_index *indexer;
	ANT_memory_index_one *one;
	ANT_parser *parser;
	char *document_buffer;

protected:
	/*
		Add a single document to the in-memory index
	*/
	void add_to_index(char *document);

	/*
		Add the top documents_to_examine documents from the results list to the in-memory index
	*/
	void populate(ANT_search_engine_result *result, long documents_to_examine);

public:
	ANT_relevance_feedback(ANT_search_engine *engine);
	virtual ~ANT_relevance_feedback();

	virtual ANT_memory_index_one_node **feedback(ANT_search_engine_result *result, long documents_to_examine, long terms_wanted) = 0;
} ;

#endif /* RELEVANCE_FEEDBACK_H_ */

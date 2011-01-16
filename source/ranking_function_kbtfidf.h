/*
	RANKING_FUNCTION_KBTFIDF.H
	--------------------------
*/
#ifndef RANKING_FUNCTION_KBTFIDF_H_
#define RANKING_FUNCTION_KBTFIDF_H_

#include "ranking_function.h"

#define ANT_RANKING_FUNCTION_KBTFIDF_DEFAULT_K 5.0 
#define ANT_RANKING_FUNCTION_KBTFIDF_DEFAULT_B 2.281718171540955

/*
	class ANT_RANKING_FUNCTION_KBTFIDF
	----------------------------------
*/
class ANT_ranking_function_kbtfidf : public ANT_ranking_function
{
private:
	double k, b;

public:
	ANT_ranking_function_kbtfidf(ANT_search_engine *engine, double k = ANT_RANKING_FUNCTION_KBTFIDF_DEFAULT_K, double b = ANT_RANKING_FUNCTION_KBTFIDF_DEFAULT_B) : ANT_ranking_function(engine) { this->k = k; this->b = b; }
	ANT_ranking_function_kbtfidf(long long documents, ANT_compressable_integer *document_lengths, double k = ANT_RANKING_FUNCTION_KBTFIDF_DEFAULT_K, double b = ANT_RANKING_FUNCTION_KBTFIDF_DEFAULT_B) : ANT_ranking_function(documents, document_lengths) { this->k = k; this->b = b; }
	virtual ~ANT_ranking_function_kbtfidf() {};

	virtual void relevance_rank_top_k(ANT_search_engine_result *accumulator, ANT_search_engine_btree_leaf *term_details, ANT_compressable_integer *impact_ordering, long long trim_point, double prescalar, double postscalar);
	virtual double rank(ANT_compressable_integer docid, ANT_compressable_integer length, unsigned char term_frequency, long long collection_frequency, long long document_frequency);
} ;



#endif /* RANKING_FUNCTION_KBTFIDF_H_ */

/*
	READABILITY_NONE.C
	------------------
*/
#include "readability_none.h"

/*
	ANT_READABILITY_NONE::GET_NEXT_TOKEN()
	--------------------------------------
*/
ANT_string_pair *ANT_readability_none::get_next_token()
{
return parser->get_next_token();
}

/*
	ANT_READABILITY_NONE::SET_DOCUMENT()
	------------------------------------
*/
void ANT_readability_none::set_document(unsigned char *document)
{
parser->set_document(document);
}


#ifndef pokerdecoder_hpp
#define pokerdecoder_hpp

#include <string>
#include "decoder.hpp"

class PokerDecoder : public CardDecoder<int, std::string> {
    static char index_to_val[13];
    static char offset_to_suite[4];
    
public:
    std::string operator()(int const & id);
};

#endif /* pokerdecoder_hpp */

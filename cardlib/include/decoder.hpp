#ifndef decoder_hpp
#define decoder_hpp

#include <cstdint>
#include <string>

namespace CardLib {

template <typename T, typename S>
class CardDecoder {
public:
    virtual S operator()(T const & id)=0;
};

}

#endif /* decoder_hpp */

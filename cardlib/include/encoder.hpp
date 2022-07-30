#ifndef encoder_hpp
#define encoder_hpp

#include <cstdint>
#include <string>

namespace CardLib {

template <typename T, typename S>
class CardEncoder {
public:
    virtual T operator()(S const & representation)=0;
};

}

#endif /* encoder_hpp */

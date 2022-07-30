#ifndef cardmanager_hpp
#define cardmanager_hpp

#include "card.hpp"
#include "encoder.hpp"

namespace CardLib {

template <typename T, typename S>
class CardManager {    
public:
    virtual Card<T,S>& get_card(S const & representation, CardEncoder<T, S> & encoder)=0;
    virtual Card<T,S>& get_card(S const & representation, std::function<T(S)> encoder_func)=0;
};

}

#endif /* cardmanager_hpp */

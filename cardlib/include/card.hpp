#ifndef card_hpp
#define card_hpp

#ifdef DEBUG
#include <iostream>
#endif

#include <cstdint>
#include <string>
#include <functional>
#include "decoder.hpp"

namespace CardLib {

// A constant class that is designed to represent a card.
template <typename T, typename S>
class Card {
    Card(Card const &)=delete;
    Card& operator=(Card const &)=delete;
    
    
public:
    const T id;
    
    Card(T const & id) : id(id) {
#ifdef DEBUG
        std::cout << "card created" << std::endl;
#endif
    }
    
    S to_representation(CardDecoder<T, S> & decoder) {
        return decoder(this->id);
    }
    
    S to_representation(std::function<S(T)> decoder_func) {
        return decoder_func(this->id);
    }
    
};

}

#endif /* card_hpp */

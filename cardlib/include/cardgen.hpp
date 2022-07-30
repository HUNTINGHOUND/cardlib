#ifndef cardgen_hpp
#define cardgen_hpp

#include <thread>
#include "card.hpp"
#include "encoder.hpp"
#include "cardmanager.hpp"

namespace CardLib {

// This class generate cards based on representation input.
template <typename T, typename S>
class CardGenerator {
    static std::mutex lock;
    
public:
    
    static Card<T, S>& get_card(S const & representation, CardEncoder<T, S> & encoder, CardManager<T, S> & card_manager) {
        std::lock_guard<std::mutex> guard(lock);
        return card_manager.get_card(representation, encoder);
    }
    
    static Card<T, S>& get_card(S const & representation, std::function<T(S)> encoder_func, CardManager<T, S> & card_manager) {
        std::lock_guard<std::mutex> guard(lock);
        return card_manager.get_card(representation, encoder_func);
    }
    
    static Card<T, S>& get_card(S const & representation, CardEncoder<T, S> & encoder, std::function<Card<T, S>&(S const &, CardEncoder<T, S> &)> get_card_func) {
        std::lock_guard<std::mutex> guard(lock);
        return get_card_func(representation, encoder);
    }
    
    static Card<T, S>& get_card(S const & representation, std::function<T(S)> encoder_func, std::function<Card<T, S>&(S const &, std::function<T(S)>)> get_card_func) {
        std::lock_guard<std::mutex> guard(lock);
        return get_card_func(representation, encoder_func);
    }
    
};

template <typename T, typename S>
std::mutex CardGenerator<T, S>::lock;

}

#endif /* cardgen_hpp */

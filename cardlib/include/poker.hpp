#ifndef poker_hpp
#define poker_hpp

#include <string>
#include "decoder.hpp"
#include "encoder.hpp"
#include "cardmanager.hpp"

namespace CardLib {

namespace PokerUtil {

class PokerManager : public CardManager<int, std::string> {
    
    Card<int, std::string> * cards[52];
    
public:
    PokerManager() {
        std::fill(this->cards, this->cards + 52, nullptr);
    }
    
    ~PokerManager() {
        for (int i = 0; i < 52; i++)
            if (this->cards[i] != nullptr) delete this->cards[i];
    }
    
    Card<int, std::string>& get_card(std::string const & representation, CardEncoder<int, std::string> & encoder) {
        int index = encoder(representation);
        
        if (this->cards[index] == nullptr)
            this->cards[index] = new Card<int, std::string>(index);
        
        return *(this->cards[index]);
    }
    
    Card<int, std::string>& get_card(std::string const & representation, std::function<int(std::string)> encoder_func) {
        int index = encoder_func(representation);
        
        if (this->cards[index] == nullptr)
            this->cards[index] = new Card<int, std::string>(index);
        
        return *(this->cards[index]);
    }
};

class PokerDecoder : public CardDecoder<int, std::string> {
public:
    std::string operator()(int const & id) {
        static char index_to_val[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        static char offset_to_suite[] = {'C', 'S', 'H', 'D'};

        
        std::string result(2, ' ');
        result[0] = index_to_val[id / 4];
        result[1] = offset_to_suite[id % 4];
        return result;
    }
};

class PokerEncoder : public CardEncoder<int, std::string> {
    
    static int get_index(char const & val) {
        static int val_to_index[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48};
        
        int index;
        if(isalpha(val)) {
            switch (val) {
                case 'A':
                    index = 0;
                    break;
                case 'T':
                    index = 9;
                    break;
                case 'J':
                    index = 10;
                    break;
                case 'Q':
                    index = 11;
                    break;
                case 'K':
                    index = 12;
                    break;
                    
                default:
                    throw std::invalid_argument("Invalid card value");
            }
        } else {
            index = val - '2' + 1;
        }
        
        return val_to_index[index];
    }
    
    static int get_offset(char const & suite) {
        static int suite_to_offset[] = {0, 1, 2, 3};
        
        int index;
        switch (suite) {
            case 'C':
                index = 0;
                break;
            case 'S':
                index = 1;
                break;
            case 'H':
                index = 2;
                break;
            case 'D':
                index = 3;
                break;
                
            default:
                throw std::invalid_argument("Invalid card suite");
        }
        
        return suite_to_offset[index];
    }
    
public:
    int operator()(std::string const & representation) {
        return get_index(representation[0]) + get_offset(representation[1]);
    }
};

}

}


#endif /* poker_hpp */

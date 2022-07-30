#include <iostream>
#include "../include/card.hpp"
#include "../include/cardgen.hpp"
#include "../include/poker.hpp"

int main() {
    CardLib::PokerUtil::PokerEncoder encoder;
    CardLib::PokerUtil::PokerDecoder decoder;
    CardLib::PokerUtil::PokerManager manager;
    CardLib::Card<int, std::string>& ace_dimond1 = CardLib::CardGenerator<int, std::string>::get_card("AC", encoder, manager);
    CardLib::Card<int, std::string>& ace_dimond2 = CardLib::CardGenerator<int, std::string>::get_card("AC", encoder, manager);
    
    CardLib::Card<int, std::string>& ace_heart1 = CardLib::CardGenerator<int, std::string>::get_card("AH", encoder, manager);
    
    std::cout << ace_dimond1.to_representation(decoder) << " " << ace_dimond2.to_representation(decoder) << " " << ace_heart1.to_representation(decoder) << std::endl;
}

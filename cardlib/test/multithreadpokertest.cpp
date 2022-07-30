#include <iostream>
#include "../include/card.hpp"
#include "../include/cardgen.hpp"
#include "../include/poker.hpp"

CardLib::PokerUtil::PokerEncoder encoder;
CardLib::PokerUtil::PokerDecoder decoder;
CardLib::PokerUtil::PokerManager manager;

void generate_card(std::string const & code) {
    CardLib::Card<int, std::string>& card = CardLib::CardGenerator<int, std::string>::get_card(code, encoder, manager);
}

int main() {
    std::thread thread1(generate_card, "AC");
    std::thread thread2(generate_card, "AC");
    std::thread thread3(generate_card, "AC");
    std::thread thread4(generate_card, "AC");
    
    std::thread thread5(generate_card, "AH");
    std::thread thread6(generate_card, "AH");
    std::thread thread7(generate_card, "AH");
    
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    
    std::cout << "Should out have 2 card created" << std::endl;
}

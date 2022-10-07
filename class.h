#include <iostream>
#include <string>

class player{
    private:
        std::string pname;
        char symbol;
    public:
        player(char symbol, std::string pname) : pname(pname), symbol(symbol){}
        std::string getName(){return this->pname;}
        char getSymbol(){return this->symbol;}
        ~player(){}

};
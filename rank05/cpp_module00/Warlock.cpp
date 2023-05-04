#include "Warlock.hpp"

Warlock::Warlock(std::string const & n, std::string const & t): name(n), title(t) {
    std::cout << name << ": this looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const & rhs) {
    *this = rhs;
}

Warlock & Warlock::operator=(Warlock const & rhs) {
    this->name = rhs.name;
    this->title = rhs.title;
    return *this;
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string const &  Warlock::getName() const {
    return this->name;
}

std::string const & Warlock::getTitle() const {
    return this->title;
}

void        Warlock::setTitle(std::string const & t) {
    this->title = t;
}

void        Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;;
}

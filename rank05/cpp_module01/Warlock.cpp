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
    std::vector<ASpell *>::iterator itS = this->magics.begin();
    std::vector<ASpell *>::iterator itE = this->magics.end();
    while (itS != itE) {
        delete *itS;
        itS++;
    }
    this->magics.clear();
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string const &  Warlock::getName() const {
    return this->name;
}

std::string const & Warlock::getTitle() const {
    return this->title;
}

void Warlock::setTitle(std::string const & t) {
    this->title = t;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;;
}

void Warlock::learnSpell(ASpell * spell) {
    std::vector<ASpell *>::iterator itS = this->magics.begin();
    std::vector<ASpell *>::iterator itE = this->magics.begin();
    if (!spell)
        return ;
    while (itS != itE) {
        if ((*itS)->getName() == spell->getName())
            return ;
        itS++;
    }
    this->magics.push_back(spell->clone());
}

void Warlock::forgetSpell(std::string const spell) {
    std::vector<ASpell *>::iterator itS = this->magics.begin();
    std::vector<ASpell *>::iterator itE = this->magics.end();
    while (itS != itE) {
        if ((*itS)->getName() == spell) {
            delete *itS;
            this->magics.erase(itS);
            return ;
        }
        itS++;
    }
}

void Warlock::launchSpell(std::string const & spell, ATarget const & target) {
    std::vector<ASpell *>::iterator itS = magics.begin();
    std::vector<ASpell *>::iterator itE = magics.end();
    while (itS != itE) {
        if ((*itS)->getName() == spell) {
            (*itS)->launch(target);
        }
        itS++;
    }
}

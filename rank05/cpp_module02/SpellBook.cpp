#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    std::vector<ASpell *>::iterator itS = this->spellbook.begin();
    std::vector<ASpell *>::iterator itE = this->spellbook.end();
    while (itS != itE) {
        delete *itS;
        itS++;
    }
    this->spellbook.clear();
}

void SpellBook::learnSpell(ASpell * spell) {
    std::vector<ASpell *>::iterator itS = this->spellbook.begin();
    std::vector<ASpell *>::iterator itE = this->spellbook.begin();
    if (!spell)
        return ;
    while (itS != itE) {
        if ((*itS)->getName() == spell->getName())
            return ;
        itS++;
    }
    this->spellbook.push_back(spell->clone());
}

void SpellBook::forgetSpell(std::string const & spell) {
    std::vector<ASpell *>::iterator itS = this->spellbook.begin();
    std::vector<ASpell *>::iterator itE = this->spellbook.end();
    while (itS != itE) {
        if ((*itS)->getName() == spell) {
            delete *itS;
            this->spellbook.erase(itS);
            return ;
        }
        itS++;
    }
}

ASpell * SpellBook::createSpell(std::string const & spell) {
    std::vector<ASpell *>::iterator itS = this->spellbook.begin();
    std::vector<ASpell *>::iterator itE = this->spellbook.end();
    while (itS != itE) {
        if ((*itS)->getName() == spell)
            return *itS;
        itS++;
    }
    return NULL;
}
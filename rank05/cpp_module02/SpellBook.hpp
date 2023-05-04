#pragma once
#include <vector>
#include "ASpell.hpp"

class SpellBook {
    public:
        SpellBook(void);
        ~SpellBook(void);

        void    learnSpell(ASpell *);
        void    forgetSpell(std::string const &);
        ASpell * createSpell(std::string const &);

    private:
        SpellBook(SpellBook const &);
        SpellBook & operator=(SpellBook const &);
        std::vector<ASpell *>   spellbook;
};

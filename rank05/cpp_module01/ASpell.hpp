#pragma once
#include <iostream>
#include "ATarget.hpp"

class ASpell {
    public:
        ASpell(void);
        ASpell(ASpell const &);
        ASpell & operator=(ASpell const &);
        ASpell(std::string const &, std::string const &);
        virtual ~ASpell(void);


        std::string const & getName(void) const;
        std::string const & getEffects(void) const;

        virtual ASpell * clone(void) const = 0;

        void launch(ATarget const &) const;
    private:
        std::string name;
        std::string effects;
    
    private:
};

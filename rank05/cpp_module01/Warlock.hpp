#pragma once

#include <string> 
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
    public:
        Warlock(std::string const &, std::string const &);
        ~Warlock();

        std::string const & getName(void) const;
        std::string const & getTitle(void) const;

        void    setTitle(std::string const &);

        void    introduce(void) const;
        void    learnSpell(ASpell *);
        void    forgetSpell(std::string const);
        void    launchSpell(std::string const &, ATarget const &);

    private:
        Warlock();
        Warlock(Warlock const &);
        Warlock & operator=(Warlock const &);

        std::string name;
        std::string title;
        std::vector<ASpell *>   magics;
};

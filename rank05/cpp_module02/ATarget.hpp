#pragma once
#include <iostream>

class ASpell;

class ATarget {
    public:
        ATarget(void);
        ATarget(std::string const &);
        ATarget(ATarget const &);
        ATarget & operator=(ATarget const &);
        virtual ~ATarget(void);

        std::string const & getType(void) const;
        virtual ATarget * clone(void) const = 0;

        void const getHitBySpell(ASpell const &) const;
    private:
        std::string type;
};

#include "ASpell.hpp"

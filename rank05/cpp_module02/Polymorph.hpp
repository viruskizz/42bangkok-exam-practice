#pragma once
#include "ASpell.hpp"

class Polymorph: public ASpell {
    public:
        Polymorph(void);
        ~Polymorph(void);

        virtual ASpell * clone(void) const;
};

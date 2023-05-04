#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const & n, std::string const & e): name(n), effects(e) {}

ASpell::ASpell(ASpell const & rhs) {
    *this = rhs;
}

ASpell  & ASpell::operator=(ASpell const & rhs) {
    this->name = rhs.name;
    this->effects = rhs.effects;
    return *this;
}

ASpell::~ASpell() {}

std::string const & ASpell::getName() const {
    return name;
}

std::string const & ASpell::getEffects() const {
    return effects;
}

void ASpell::launch(ATarget const & target) const {
    target.getHitBySpell(*this);
}
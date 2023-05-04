#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const & t): type(t) {}

ATarget::ATarget(ATarget const & rhs) {
    *this = rhs;
}

ATarget & ATarget::operator=(ATarget const & rhs) {
    this->type = rhs.type;
    return *this;
}

ATarget::~ATarget() {}

std::string const & ATarget::getType() const {
    return this->type;
}

void const ATarget::getHitBySpell(ASpell const & spell) const {
    std::cout << type << " has benn " << spell.getEffects() << "!" << std::endl;
}
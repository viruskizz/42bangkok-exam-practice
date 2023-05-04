#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::TargetGenerator(TargetGenerator const & rhs) {
    *this = rhs;
}
TargetGenerator & TargetGenerator::operator=(TargetGenerator const & rhs) {
    this->targets = rhs.targets;
    return *this;
}
TargetGenerator::~TargetGenerator() {
    std::vector<ATarget *>::iterator itS = this->targets.begin();
    std::vector<ATarget *>::iterator itE = this->targets.end();
    while (itS != itE) {
        delete *itS;
        itS++;
    }
    this->targets.clear();
}

void TargetGenerator::learnTargetType(ATarget * t) {
    std::vector<ATarget *>::iterator itS = this->targets.begin();
    std::vector<ATarget *>::iterator itE = this->targets.end();
    while (itS != itE) {
        if ((*itS)->getType() == t->getType())
            return ;
        itS++;
    }
    this->targets.push_back(t->clone());
}

void TargetGenerator::forgetTargetType(std::string const & t) {
    std::vector<ATarget *>::iterator itS = this->targets.begin();
    std::vector<ATarget *>::iterator itE = this->targets.end();
    while (itS != itE) {
        if ((*itS)->getType() == t) {
            delete *itS;
            this->targets.erase(itS);
            return ;
        }
        itS++;
    }
}

ATarget * TargetGenerator::createTarget(std::string const & t) {
    std::vector<ATarget *>::iterator itS = this->targets.begin();
    std::vector<ATarget *>::iterator itE = this->targets.end();
    while (itS != itE) {
        if ((*itS)->getType() == t)
            return *itS;
        itS++;
    }
    return NULL;
}
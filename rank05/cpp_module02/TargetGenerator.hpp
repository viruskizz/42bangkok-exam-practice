#pragma once
#include "ATarget.hpp"
#include <vector>

class ATarget;

class TargetGenerator {
    public:
        TargetGenerator(void);
        ~TargetGenerator(void);

        void learnTargetType(ATarget *);
        void forgetTargetType(std::string const &);
        ATarget * createTarget(std::string const &);
    private:
        TargetGenerator(TargetGenerator const &);
        TargetGenerator & operator=(TargetGenerator const &);
        std::vector<ATarget *> targets;
};

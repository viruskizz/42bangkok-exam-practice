#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Pracice Dummy") {}

Dummy::~Dummy() {}

ATarget * Dummy::clone() const {
    return (new Dummy());
}

#include "Dollar.h"
#include "string"

std::string Dollar::toString() {
	return this->getWhole() << "." << this->getFrac() << " " << this->getName();
}

bool Dollar::isEqual(Currency& right) {
	if (right.getWhole() != this->getWhole() || right.getFrac() != this->getFrac()) {
		return false;
	}
	else {
		return true;
	}
}

bool Dollar::isGreater(Currency& right) {
	if (this->getWhole() == right.getWhole() && this->getFrac() > right.getWhole()) {
		return true;
	}
	if (this->getWhole() > right.getWhole()) {
		return true;
	}
	if (this->getWhole() == right.getWhole() && this->getFrac() < right.getFrac()) {
		return false;
	}
	if (this->getWhole() < right.getWhole()) {
		return false;
	}
	if (this->isEqual(right)) {
		return false;
	}
}

std::string Dollar::getName
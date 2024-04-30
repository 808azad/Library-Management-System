#include "Streamable.h"
using namespace std;

namespace sdds {

	Streamable::~Streamable(){}

	ostream& operator<<(ostream& os, const Streamable& stream) {
		stream.write(os);
		return os;
	}

	istream& operator>>(istream& is, Streamable& stream) {
		stream.read(is);
		return is;
	}

}
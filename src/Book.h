#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include "Publication.h"

namespace sdds {

	class Book : public Publication {
		char* m_author{ nullptr };
	public:
		Book();
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
		const char type() const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		void set(int id);
		operator bool() const;
	};


}


#endif // !SDDS_BOOK_H


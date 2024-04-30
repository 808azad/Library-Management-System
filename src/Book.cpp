#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string>
#include <cstring>
#include "Book.h"
#include "Utils.h"
using namespace std;

namespace sdds {

	Book::Book() : Publication() {
		m_author = nullptr;
	}

	Book::Book(const Book& book) : Publication(book) {
		if (book.m_author != nullptr && book.m_author[0] != '\0') {
			m_author = new char[strlen(book.m_author) + 1];
			strcpy(m_author, book.m_author);
		}
	}

	Book& Book::operator=(const Book& book) {
		if (this != &book) {
			if (m_author) {
				delete[] m_author;
				m_author = nullptr;
			}
			Publication::operator=(book);
			if (book.m_author != nullptr && book.m_author[0] != '\0') {
				m_author = new char[strlen(book.m_author) + 1];
				strcpy(m_author, book.m_author);
			}
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}

	const char Book::type() const {
		char b = 'B';
		return b;
	}

	ostream& Book::write(ostream& os = cout) const {
		Publication::write(os);//
		if (conIO(os)) {
			if (*this) {
				os << " ";  
				const string temp = m_author;
				string txt;
				if (temp.length() > SDDS_AUTHOR_WIDTH) {
					txt = temp.substr(0, SDDS_AUTHOR_WIDTH);
				}
				else {
					txt = temp;
				}
				os << left << setw(SDDS_AUTHOR_WIDTH) << setfill(' ') << txt;
				os << " |";
			}
		}
		else {
			os << "\t";
			os << m_author;
		}
		return os;
	}

	istream& Book::read(istream& is = cin) {
		char authorName[256]{};
		Publication::read(is);
		if (m_author) {
			delete[] m_author;
			m_author = nullptr;
		}
		if (conIO(is)) {
			is.ignore();
			cout << "Author: ";
			is.get(authorName, 255);
		}
		else { 
			is.ignore(1, '\t');
			is.get(authorName, 255);
		}
		if (!is.fail()) {
			m_author = new char[strlen(authorName) + 1];
			strcpy(m_author, authorName);
		}
		return is;
	}

	void Book::set(int id) {
		Publication::set(id);
		Publication::resetDate();
	}

	Book::operator bool() const {
		return (m_author != nullptr && m_author[0] != '\0' && Publication::operator bool());
	}


}
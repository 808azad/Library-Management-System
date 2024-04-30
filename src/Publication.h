#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Lib.h"
#include "Date.h"
#include "Streamable.h"

namespace sdds {

	class Publication : public Streamable{
		char* m_title{nullptr}; //m_title is a c-string to hold a dynamic title for the publication.
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]{}; //Hold the location of the publication in the library. m_shelfId is a c-string that is exactly 4 characters long.
		int m_membership{}; //In this class, if the membership number is '0', it means the publication is available and is not checked out by any members
		int m_libRef{}; //This serial number is used internally to uniquely identify each publication in the system.
		Date m_date{}; //In periodical publications, this date is used for the publish date of the item, in books, to keep the date on which the book was borrowed by the member.
	public:
		Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual const char type() const;
		bool onLoan() const;
		Date checkoutDate() const;
		bool operator==(const char* title) const;
		operator const char* () const;
		int getRef() const;
		char* getTitle() const;
		bool conIO(std::ios& io) const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		Publication(const Publication& pbl);
		Publication& operator=(const Publication& pbl);
		virtual ~Publication();
	};

}



#endif // !SDDS_PUBLICATION_H


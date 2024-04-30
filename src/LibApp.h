#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"
#include "PublicationSelector.h"
#include "Publication.h"
#include "Book.h"
#include "Lib.h"

namespace sdds {
   class LibApp {
	   bool m_changed = false; //flag to keep track of changes made to the application data
	   Menu m_mainMenu{}; //will be used as a main menu of the application
	   Menu m_exitMenu{};
	   char m_filename[256]{};
	   Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{ nullptr };
	   Menu m_typePublication{};
	   int m_NOLP{};
	   int m_LLRN{};
	   bool confirm(const char* message);
	   void populateObj();
	   void load();
	   void save();
	   PublicationSelector* search(int mode);
	   Publication* getPub(int libRef);
	   void returnPub();
	   void newPublication();
	   void removePublication();
	   void checkOutPub();
   public:
	   LibApp(const char* filename);
	   ~LibApp();
	   void run();
   };

}
#endif // !SDDS_LIBAPP_H




#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>
#include "Utils.h"

namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem {
		char* m_content{ nullptr };
		void setEmpty();
		MenuItem();
		MenuItem(const char* receivedItem);
		MenuItem(const MenuItem& menuItem) = delete;
		MenuItem& operator=(const MenuItem& menuItem) = delete;
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		std::ostream& display(std::ostream& os = std::cout) const;
		friend class Menu;
	};

	class Menu {
		MenuItem m_title{}; // for title
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{ nullptr }; //for the items
		unsigned int m_count{}; //for tracking the number of menu items
	public:
		Menu();
		Menu(const char* title);
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;
		~Menu();
		std::ostream& displayTitle(std::ostream& os = std::cout) const ;
		std::ostream& displayMenu(std::ostream& os = std::cout) const;
		unsigned int run();
		operator bool() const;
		operator int() const;
		operator unsigned int() const;
		Menu& operator<<(const char* menuItemContent);
		const char* operator[](unsigned int index) const;
		unsigned int operator~();
	};
	extern Utils util;
	std::ostream& operator<<(std::ostream& os, const Menu& menu);

}

#endif
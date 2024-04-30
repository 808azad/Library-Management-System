#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <fstream>
#include "LibApp.h"
using namespace std;

namespace sdds {


	bool LibApp::confirm(const char* message) {
		int res = 0;
		if (message != nullptr && message[0] != '\0') {
			Menu confirmMenu(message);
			confirmMenu << "Yes";
			res = confirmMenu.run();
		}
		return res == 1;
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
		ifstream file(m_filename);
		if (!file) {
			cerr << "Could not open a file!" << endl;
		}
		else {
			char pblType{};
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]) {
					delete m_PPA[i];
					m_PPA[i] = nullptr;
				}
			}
			m_NOLP = 0;
			for (int j = 0; file; j++) {
				file >> pblType;
				if (file) {
					if (pblType == 'P') {
						m_PPA[j] = new Publication;
					}
					else if (pblType == 'B') {
						m_PPA[j] = new Book;
					}
					if (m_PPA[j]) {
						file >> *m_PPA[j];
						m_NOLP++;
					}
				}
			}
			if (m_NOLP > 0) {
				m_LLRN = m_PPA[m_NOLP - 1] -> getRef();
				m_LLRN++;
			}
		}
		file.close();
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream outFile(m_filename); 
		if (!outFile) {
			cout << "Could not open a file! Error: " << strerror(errno) << endl;
		}
		else {
			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->getRef() != 0) {
					if (m_PPA[i]->getRef() == -1) {
						m_PPA[i]->setRef(m_LLRN);
						m_LLRN++;
					}
					outFile << *m_PPA[i] << endl;
				}
			}
			outFile.close();
		}
	}

	PublicationSelector* LibApp::search(int mode) {
		PublicationSelector* pblSelector{ nullptr };
		pblSelector = new PublicationSelector("Select one of the following found matches:");
		char buffer[256]{};
		bool done = false;
		cout << "Choose the type of publication:" << endl;
		int choice = m_typePublication.run();
		char type{};
		if (choice == 0) {
			cout << "Aborted!" << endl;
		}
		else {
			if (choice == 1) type = 'B';
			else if (choice == 2) type = 'P';
			cout << "Publication Title: ";
			cin.get(buffer, 255);
			cin.ignore(10000, '\n');
			for (int i = 0; i < m_NOLP; i++) {
				bool equal = strstr(m_PPA[i]->getTitle(), buffer) != nullptr;
				if (m_PPA[i]->getRef() != 0) {
					if (m_PPA[i]->type() == type) {
						if (equal) {
							if ((mode == 0) || (mode == 1 && m_PPA[i]->onLoan()) || (mode == 2 && !m_PPA[i]->onLoan())) {
								*pblSelector << m_PPA[i];
								done = true;
							}
						}	
					}
				}
			}
			if (!done) {
				cout << "No matches found!" << endl;
				delete pblSelector;
				pblSelector = nullptr;

			}
			else {
				if (pblSelector) {
					pblSelector->sort();
				}
			}
		}
		return pblSelector;
	}


	void LibApp::newPublication() {
		if (m_NOLP < SDDS_LIBRARY_CAPACITY) {
			cout << "Adding new publication to the library" << endl;
			cout << "Choose the type of publication:" << endl;
			int choice = m_typePublication.run();
			if (choice == 0) {
				cout << "Aborted!" << endl << endl;
			}
			else {
				Publication* p{ nullptr };
				if (choice == 1) {
					p = new Book;
				}
				else if (choice == 2) {
					p = new Publication;
				}
				if (p) {
					cin >> *p;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
					}
					cin.ignore(10000, '\n');
				}
				if (confirm("Add this publication to the library?")) {
					m_PPA[m_NOLP] = p;
					m_NOLP++;
					m_changed = true;
					cout << "Publication added" << endl;
				}
				else {
					cout << "Failed to add publication!" << endl;
					delete p;
				}
				cout << endl;
			}
		}
		else {
			cout << "Library is at its maximum capacity!" << endl;
			cout << endl;
		}
	}


	Publication* LibApp::getPub(int getRef) {
		int i{};
		bool done = false;
		for (i = 0; !done && i < m_NOLP; i++) {
			if (m_PPA[i]->getRef() == getRef) {
				done = true;
			}
		}
		return m_PPA[i - 1];
	}

	void LibApp::returnPub() {
		cout << "Return publication to the library" << endl;
		ostream& os = cout;
		PublicationSelector* pblSelect = search(1);
		Publication* pbl{ nullptr };
		if (pblSelect) {
			int choice = pblSelect->run();
			if (choice > 0) {
				pbl = getPub(choice);
				pbl->write(os) << endl;
				if (confirm("Return Publication?")) {
					int onLoanDate = Date() - pbl->checkoutDate();
					if (onLoanDate > SDDS_MAX_LOAN_DAYS) {
						double penaltyAmount = (onLoanDate - SDDS_MAX_LOAN_DAYS) * 0.5;
						cout << "Please pay $" << fixed << setprecision(2) << penaltyAmount << " penalty for being " << onLoanDate - SDDS_MAX_LOAN_DAYS << " days late!" << endl;
					}
					pbl->set(0);
					m_changed = true;
					cout << "Publication returned" << endl;
				}
			}
			delete pblSelect;
		}
		cout << endl;
	}

	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;
		ostream& os = cout;
		PublicationSelector* pblSelect = search(0);
		Publication* pbl{ nullptr };
		if (pblSelect) {
			int choice = pblSelect->run();
			if (choice == 'X') {
				cout << "Aborted!" << endl;
			}
			else {
				if (choice > 0) {
					pbl = getPub(choice);
					pbl->write(os) << endl;
   					if (confirm("Remove this publication from the library?")) {
						pbl->setRef(0);
						m_changed = true;
						cout << "Publication removed" << endl;
					}
				}
			}
			delete pblSelect;
		}
		cout << endl;
	}

	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		ostream& os = cout;
		PublicationSelector* pblSelect = search(2);
		Publication* pbl{ nullptr };
		if (pblSelect) {
			int choice = pblSelect->run();
			if (choice > 0) {
				pbl = getPub(choice);
				pbl->write(os) << endl;
				if (confirm("Check out publication?")) {
					cout << "Enter Membership number: ";
					int membership = util.readInt(10000, 99999, "Invalid membership number, try again: ");
					pbl->set(membership);
					m_changed = true;
					cout << "Publication checked out" << endl;
				}
			}
			delete pblSelect;
		}
		cout << endl;
	}

	void LibApp::populateObj() {
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_typePublication << "Book";
		m_typePublication << "Publication";
	}

	LibApp::LibApp(const char* filename) :
		m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		if (filename != nullptr && filename[0] != '\0') {
			strcpy(m_filename, filename);
		}
		for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++) {
			m_PPA[i] = nullptr;
		}
		m_changed = false;
		populateObj();
		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
			m_PPA[i] = nullptr;
		}
	}

	void LibApp::run() {
		bool done = false;
		while (!done) {
			int choice = m_mainMenu.run();
			switch (choice) {
				case 1:
					newPublication();
					break;
				case 2:
					removePublication();
					break;
				case 3:
					checkOutPub();
					break;
				case 4:
					returnPub();
					break;
				default:
					if (m_changed) {
						int choice2 = m_exitMenu.run();
						switch (choice2) {
							case 1:
								save();
								done = true;
								break;
							case 2:
								m_changed = true;
								cout << endl;
								break;
							default:
								if (confirm("This will discard all the changes are you sure?")) {
									done = true;
								}
								else {
									m_changed = false;
								}
						}
					}
					else {
						done = true;
					}
			}
		}
		cout << endl << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

}

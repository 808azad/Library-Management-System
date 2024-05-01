# Project: Library-Management-System for Seneca

## About:

When new books and other publications arrive in the Seneca Library, it's crucial to ensure they are efficiently processed and made available for lending. This involves tagging each publication with relevant information and organizing them on shelves in a way that makes them easy to find when needed.

The main task is to design an application that automates this process. The application should receive information about each publication as it arrives and store it into the library's system. This information include details such as the title, author, publication date, and location on the shelves.

Each publication can be lent out to members of the library with a due date for return. A penalty amount must be applied if a library member fails to return a borrowed publication by the due date.

## Compiling and Testing The Program

To compile and test how this program works, use the following command:

```bash
g++ -Wall -std=c++11 -g -o libApplication file1.cpp file2.cpp ...
```

## Files To Use
Use the files mentioned below to compile the program:
```Text
Lib.h
Utils.cpp
Utils.h
Date.cpp
Date.h
Menu.cpp
Menu.h
Streamable.cpp
Streamable.h
Publication.cpp
Publication.h
Book.cpp
Book.h
PublicationSelector.cpp
PublicationSelector.h
LibApp.cpp
LibApp.h
LibAppMain.cpp
LibRecs.txt
LibRecsSmall.txt
```

## Data Entries For Testing
To observe in detail how each operation of the program works, utilize the provided data below:
### Data Entry #1
Data file: [LibRecsSmall.txt](src/LibRecsSmall.txt)

- load
- Book and Publication entry
- setting the library reference number
- save

Entry:
```Text
1
1
S001
Book one
2023/8/5
John Doe
1
1
2
S002
Daily one
2023/8/5
1
0
1
```
### Data Entry #2
Data file: [LibRecsSmall.txt](src/LibRecsSmall.txt)

- load
- Removing Publication and Book
- save

Data Entry:
```Text
2
1
e
3
1
2
2
e
3
1
0
1
```
### Data Entry #3
Data file: [LibRecsSmall.txt](src/LibRecsSmall.txt)

- load
- Checking out and no match found
- Checking out with success
- save

Data Entry:
``` Text
3
1
Harry
3
1
Web
1
1
12345
0
1
```
### Data Entry #4

Data file: [LibRecsSmall.txt](src/LibRecsSmall.txt)

- load
- Returning a Book with no penalty
- Returning a Book with penalty
- Returning a Publication
- save

Data Entry:
```Text
4
1
Harry
1
1
4
1
Hobbit
1
1
4
2
e
2
1
0
1
```
### Data Entry #5
Data file: [LibRecs.txt](src/LibRecs.txt)

>Before starting this this test make sure that in "Lib.h" <br />
The maximum capacity of the library is set to 333. <br />`>>  const int SDDS_LIBRARY_CAPACITY = 333;  <<`
The file: [Lib.h](src/Lib.h)

- load
- Adding a publication
- Add another publication unsuccessfully
- save

Data Entry:
```Text
1
2
S003
News Daily
2023/8/5
1
1
0
1
```

### Data Entry #6
Data file: [LibRecs.txt](src/LibRecs.txt)

- load
- Aborting and error handling
- exit without saving

Data Entry:
```Text
1
0
2
2
<ENTER>
x
3
1
<ENT ER>
1
1
123456
12345
4
2
<ENTER>
x
0
0
1
```

### Sample Data Entry:
```Text
Loading Data
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 1
Adding new publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Shelf No: S001
Title: Book one
Date: 2023/8/5
Author: John Doe
Add this publication to the library?
 1- Yes
 0- Exit
> 1
Publication added

Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 1
Adding new publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Shelf No: S002
Title: Daily one
Date: 2023/8/5
Add this publication to the library?
 1- Yes
 0- Exit
> 1
Publication added

Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 0
Changes have been made to the data, what would you like to do?
 1- Save changes and exit
 2- Cancel and go back to the main menu
 0- Exit
> 1
Saving Data

-------------------------------------------
Thanks for using Seneca Library Application
B	1001	C544	The Hobbit	35277	2023/07/14	J. R. R. Tolkien
B	1002	D208	Harry Potter and the Philosopher's Stone	72685	2023/07/28	J. K. Rowling
P	1018	P002	The Toronto SUN	85176	2023/07/17
P	1019	P002	The Toronto SUN	0	2023/07/11
B	1048	N518	The Bridges of Madison County	15467	2023/07/14	Robert James Waller
B	1061	Z192	Charlotte's Web	0	2023/07/17	E. B. White; illustrated byGarth Williams
B	1062	V718	The Tale of Peter Rabbit	0	2023/07/12	Beatrix Potter
P	1093	P008	Canadian Running Magazine	77051	2023/07/25
P	1094	P008	Canadian Running Magazine	0	2023/07/18
B	1095	S001	Book one	0	2023/08/05	John Doe
P	1096	S002	Daily one	0	2023/08/05
```

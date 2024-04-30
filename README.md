# Project: Library-Management-System for Seneca

## About:

When new books and other publications arrive in the Seneca Library, it's crucial to ensure they are efficiently processed and made available for lending. This involves tagging each publication with relevant information and organizing them on shelves in a way that makes them easy to find when needed.

The main task is to design an application that automates this process. The application should receive information about each publication as it arrives and store it into the library's system. This information include details such as the title, author, publication date, and location on the shelves.

Each publication can be lent out to members of the library with a due date for return. A penalty amount must be applied if a library member fails to return a borrowed publication by the due date.

## Compiling and Testing The Program

To compile and test how this program works, use the following command:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
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
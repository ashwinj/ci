CI interpreter

* CI is a small interpreter for c language written completely in c itself.
* This project is licensed under the terms of the GNU GPL v3.0.
* Lexer and parser are generated using flex and bison.
* The flex and bison files are heavily influenced by the grammar rules discussed
  in K&R book.
* TODO and FIXME:
	1. shady implementation of 2d arrays and pointers.	
	2. shady implementation of type. basically, we would like to change
	   the current handling of types with a more generic one.
	3. improve error handling module to include more information.
	   this will require addition of fields in the ast data structure
	   and a data structure to encapsulate the error object.
	4. better commenting and documentation.

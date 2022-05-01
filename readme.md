# threeD Lexer Assignment

## Setup Instructions

* Fork the repo to create a copy of the repository on your own github account

![](https://imgur.com/H7kYE5I.png)


* Clone the repo
	```bash
	git clone --recursive https://github.com/{Your Username}/threeD
	```

* You can build the project by running the following command in the root directory of the project
	```bash
	cmake -Bbuild
	cmake --build build
	```
* You can run the project by running the following command in the root directory of the project
	```bash
	./build/Lexer
	```
	OR
	```bash
	./build/Debug/Lexer #(if your compiler is MSVC)
	```

* You want to make all the test cases pass. The tds files and their outputs are located in [tests/cases](tests/cases/)

* In order to run all the tests at once, run the following command after building

	```bash
	ctest --test-dir build --output-on-failure
	```
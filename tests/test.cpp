#include <gtest/gtest.h>

#include "lexer.hpp"

#include <filesystem>
#include <fstream>

#include <iostream>

#ifndef CASES_DIR
#define CASES_DIR "cases"
#endif

// Demonstrate some basic assertions.
TEST(LexerTest, TestCases) {

	// Locate all files case*.tds in cases directory.
	for (auto& entry : std::filesystem::directory_iterator(CASES_DIR)) {
		if (entry.path().extension() == ".tds" && entry.path().filename().string().substr(0, 4) == "case") {

			// Get number of case.
			auto caseNumber = entry.path().stem().string().substr(4, entry.path().stem().string().size() - 4);

			// Open file.
			std::ifstream file(entry.path());

			// Create lexer.
			Lex::Lexer lexer;

			// Read file into string
			std::stringstream buffer;
			buffer << file.rdbuf();

			// Set translation unit.
			lexer.setTranslationUnit(buffer.str());

			// Initialize token array
			std::vector<Lex::Token> tokens;


			// Keep lexing until end of file.
			while(!lexer.eof()) {
				// Lex next token.
				auto token = lexer.lexNextToken();

				// Add token to array.
				tokens.push_back(token);
			}

			// Close file.
			file.close();

			std::filesystem::path filePath = entry.path();

			// Open testcase output file.
			std::ifstream outputFile(filePath.replace_extension(".out"));

			// Get all lines from output file into array
			std::vector<std::string> outputLines;
			std::string line;
			while (std::getline(outputFile, line)) {
				outputLines.push_back(line);
			}

			// Close output file.
			outputFile.close();

			// Compare tokens with output file.
			EXPECT_EQ(outputLines.size(), tokens.size()) << "Case " + caseNumber + ": Number of tokens do not match.";

			for (size_t i = 0; i < tokens.size(); i++) {
				// Compare token string representation.
				EXPECT_EQ(outputLines[i], tokens[i].stringRepresentation()) << "Case " + caseNumber + ": Expected Token " + outputLines[i] + " does not match your output " + tokens[i].stringRepresentation();
			}

		}
	}
}
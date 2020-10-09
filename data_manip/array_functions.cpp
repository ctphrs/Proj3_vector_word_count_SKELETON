#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include "../includes/constants.h"
#include "../includes/array_functions.h"
#include "../includes/utilities.h"

namespace KP{
	//zero out vector that tracks words and their occurrences
	void clear(std::vector<constants::entry>  &entries){
	entries.clear();
	}
	//how many unique words are in the vector
	int getSize(std::vector<constants::entry>  &entries){
		return entries.size();
	}

	//get data at a particular location, if i>size() then get the last value in the vector
	//(this is lazy, should throw an exception instead)
	std::string getWordAt(std::vector<constants::entry>  &entries, int i){
		return entries[i].word;
	}
	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i){
		return entries[i].number_occurences;
	}

	/*loop through whole file, one line at a time
		 * call processLine on each line from the file
		 * returns false: myfstream is not open
		 *         true: otherwise*/
	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream){
			std::string str;
			if(!myfstream.is_open())
				return false;
			while(getline(myfstream, str)){
					processLine(entries, str);
			}
			return true;
		}
	/*take 1 line and extract all the tokens from it
 	 feed each token to processToken for recording*/
	void processLine(std::vector<constants::entry> &entries, std::string &myString) {
		std::stringstream ss(myString);
		std::string tempToken;

		while(getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)){
			processToken(entries, tempToken);
		}
	}
	/*Keep track of how many times each token seen*/
	void processToken(std::vector<constants::entry> &entries, std::string &token) {

		if(!strip_unwanted_chars(token)){
		            return;
		        }
		        int index = -1;
		        for(int i = 0; i < entries.size(); i++){
		            if (entries[i].word == token){
		                index = i;
		                break;
		            }
		        }
		        if (index == -1){
		            std::string upper_token = token;
		            toUpper(upper_token);
		            constants::entry new_entry = {token, upper_token, 1};
		            entries.push_back(new_entry);
		        }
		        else {
		            entries[index].number_occurences += 1;
		        }
//Coulf not get this code to work so did it another way
//		for(int i=0; i<entries.size(); i++){
//			strip_unwanted_chars(token);
//		           if(token!=entries[i].word){
//		               // Make a version of the token thats uppercase to store in our new struct
//		               std::string token_upper = token;
//		               toUpper(token_upper);
//		               // Make a new entry struct with the value of token
//		               constants::entry entry_token{token, token_upper,1};
//		               entries.push_back(entry_token);
//		                }
//		                if(token==entries[i].word){
//		                    entries[i].number_occurences++;
//		            }
//		        }
	}
	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */
	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){

	}
}

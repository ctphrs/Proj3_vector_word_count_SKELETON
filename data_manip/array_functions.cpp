#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
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

	}
	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */
	bool compare_asc(constants::entry &a, constants::entry &b){
		return a.word<b.word;
	}
	bool compare_dec(constants::entry &a, constants::entry &b){
			return a.word>b.word;
		}
	bool compare_num(constants::entry &a, constants::entry &b){
			return a.number_occurences>b.number_occurences;
		}

	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){
		if(so == constants::NONE){
			return;
		}
		if(so == constants::ASCENDING){
			sort(entries.begin(), entries.end(), compare_asc);
				}
		if(so == constants::DESCENDING){
					sort(entries.begin(), entries.end(), compare_dec);
						}
		if(so == constants::NUMBER_OCCURRENCES){
							sort(entries.begin(), entries.end(), compare_num);
								}
	}
}

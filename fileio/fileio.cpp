#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../includes/constants.h"
/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in){
	return true; //Unimplementerd
}

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile){
	//Unimplemented
}

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){
	return 3; //Unimplemented
}

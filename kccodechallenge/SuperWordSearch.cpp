#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	//1. Handle file parsing.  
    std::ifstream infile("inputtest1.txt");
    
    std::string line;
    int nRowValue = 0;
    int mColValue = 0;

    //First take care of filling out the wordsearch 2d array
    std::getline(infile, line);

    std::istringstream issLineOne(line);
        
    issLineOne >> nRowValue;
    //std::cout << "\nES: There are " << nRowValue << " rows";
    issLineOne >> mColValue;
    //std::cout << "\nES: There are " << mColValue << "cols ";
    char wordMatrix[mColValue][nRowValue];
    for(int i = 0; i < nRowValue; i++)
    {
        std::getline(infile, line);
        //std::cout << "\nES: Value of line: " << line;
        for(int j = 0; j < line.size(); j++)
        {
        	wordMatrix[i][j] = line[j];
        	//std::cout << "\nES: Just set letter at row " << i << " col " << j << " to char value " << line[j];
        }
    }
    //Done filling out the word matrix
    std::getline(infile, line);
    bool isWrapAround = false;
    if(line == "NO_WRAP")
    {
    	isWrapAround = false;
    	//std::cout << "no wrap around";
    }
    else if(line == "WRAP")

    {
    	isWrapAround = true;
    }
    else
    {
    	std::cout << "\nBad wraparound command";
    	exit(0);
    }

    std::vector<std::string> searchLines;
    std::getline(infile, line);
    std::istringstream issLineSix(line);
    int searchLineNum = 0;
    issLineSix >> searchLineNum;
    //std::cout << "\nES: Value of searchLineNum: " << searchLineNum;
    for(int i = 0; i < searchLineNum; i++)
    {
    	std::getline(infile, line);
    	searchLines.push_back(line);
    	//std::cout << "\nJust pushed search string " << line << "\nTo vector";
    }

    //2. Carry out search
    
	//ES: I liked the way Geeksforgeeks did this.  Two 1D arrays are used to represent the possible directions
	//https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/

	int xArr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
	int yArr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    int matchStartRow = 0;
    int matchEndRow = 0;
    int matchStartCol = 0;
    int matchEndCol = 0;
    for(int x = 0; x < searchLines.size(); x++) //for every word in the word list vector
	{
		bool wordMatches = false;
		std::cout << "\nCANDIDATE WORD: " << searchLines[x];
		for(int i = 0; i < nRowValue; i++) //for every row
		{
			for(int j = 0; j < mColValue; j++) //for every column
			{
				//std::cout << "\nCandidate char: " << wordMatrix[i][j];
            	//x is for the word
				
				for(int dir = 0; dir < 8; dir++) //Geeksforgeeks
				{
					
					// Initialize starting point for current direction 
                    int y = 0; 
    				if(searchLines[x].at(0) == wordMatrix[i][j]) //if the first letter doesn't match, it's not a candidate
    				{
    					int len = searchLines[x].size();
    					std::cout << "\nFIRST LETTER: A match was found for " << wordMatrix[i][j] << " at row " << i << " and col " << j;
    					int startingRow = i;
    					int startingCol = j;
    					int curRow = i + xArr[dir];
    					int curCol = j + yArr[dir];
    					std::cout << "\n****CHECK TO SEE IF ROW " << curRow << " col " << curCol << " is a valid extension char";
    				    //y is for the letter of the word
    				    for(y = 1; y < len; y++)
    				    {
    				    	
				            if (curRow >= nRowValue || curCol < 0 || curCol >= mColValue  || curCol < 0) 
				            {
				            	std::cout << "\nBound exceeded at row " << curRow << " and col " << curCol;
				                break; 
				            }
				  
				            // If not matched,  break 
				            if (wordMatrix[curRow][curCol] != searchLines[x].at(y)) 
				            {
				            	std::cout << "\nBreak.  The letter " << wordMatrix[curRow][curCol] << " does not match " << searchLines[x].at(y);
				                break; 
				            }
				  
				            //  Moving in particular direction 
				            std::cout << "\nOkay, keep going.  This is good.  Continue to add. Looks like row " << curRow << " col " << curCol << " was a valid extension";
				            if(y + 1 != len)
				            {
				                curRow += xArr[dir], curCol += yArr[dir]; 
				            }
				            std::cout << "\n Now trying row " << curRow << " and col " << curCol;
				            std::cout << "\nAT THIS POINT, Y IS " << y << " and len is " << len;
				            if(y + 1 == len)
				            {
				            	std::cout << "\n\n\n\n******MATCH FOUND start coor " << startingRow << " " << startingCol << " end row " << curRow << " end col " << curCol;
				            	matchStartRow = startingRow;
				            	matchStartCol = startingCol;
				            	matchEndRow = curRow;
				            	matchEndCol = curCol;
				            	
				            	wordMatches = true;
				            	std::cout << "\nI WANNA SAVE THESE GUYS OFF AND BREAK OUT";
				            	//goto endloop;
				            	break;

				            }

				            wordMatches = false;

    					    
    				    }
    				    //std::cout << "\nBreak brought us here";
    				    


			    	}
			    	
			    }
				
				std::cout << "\nThe word does not match.  Go on to the next one";
				
			}
			
			
		}
		//endloop:
		if(wordMatches == true)
		{
			std::cout << "\nOkay so we have a match on word " << searchLines[x];
			std::cout << "\nIt's start " << matchStartRow << " " << matchStartCol << "\nand end " << matchEndRow << " " << matchEndCol;
			std::cout << "(" << matchStartRow << "," << matchStartCol << ")(" << matchEndRow << "," << matchEndCol << ")";
		}
		else
		{
			std::cout << "\nNo match for word" << searchLines[x];
			std::cout << "\nNOT FOUND"; //just keep going
		}

	}
    

	return 0;
}
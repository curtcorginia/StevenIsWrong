#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	//1. Handle file parsing.  
    //std::ifstream infile("inputtest1.txt");
    std::ifstream infile("WRAPAROUND.txt");
    
    std::string line;
    int nRowValue = 0;
    int mColValue = 0;

    //First take care of filling out the wordsearch 2d array
    std::getline(infile, line);

    std::istringstream issLineOne(line);
        
    issLineOne >> nRowValue;
    issLineOne >> mColValue;
    char wordMatrix[mColValue][nRowValue];
    for(int i = 0; i < nRowValue; i++)
    {
        std::getline(infile, line);
        for(int j = 0; j < line.size(); j++)
        {
        	wordMatrix[i][j] = line[j];
        }
    }
    //Done filling out the word matrix
    std::getline(infile, line);
    bool isWrapAround = false;
    std::cout << "\nVALUE OF LINE: " << line;
    line.erase(std::find(line.begin(), line.end(), '\0'), line.end());
    line.erase(std::find(line.begin(), line.end(), ' '), line.end());
    std::cout << "\nVALUE OF LINE: " << line;
    if(line == "NO_WRAP")
    //if(line.at(0) == "N" && line.at(1) == "O")
    {
    	std::cout << "\nYOU'RE NOT IN WRAPAROUND MODE";
    	isWrapAround = false;
    }
    else if(line == "WRAP")
    //else if(line.at(0) == "W" && line.at(1) == "R")
    {
    	std::cout << "\nYOU'RE IN WRAPAROUND MODE";
    	isWrapAround = true;
    }
    else
    {
    	std::cout << "\nThe value of line is " << line;
    	std::cout << "\nBad wraparound command";
    	exit(0);
    }

    std::vector<std::string> searchLines;
    std::getline(infile, line);
    std::istringstream issLineSix(line);
    int searchLineNum = 0;
    issLineSix >> searchLineNum;
    for(int i = 0; i < searchLineNum; i++)
    {
    	std::getline(infile, line);
    	searchLines.push_back(line);
    }

    //2. Carry out search
    
	//ES: I liked the way Geeksforgeeks did this.  Two 1D arrays are used to represent the possible directions
	//https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
	//
	//A few differences between their method and mine:
	//	-I started by finding the first matching letter 
	//  -I used a vector of words
	//  -Because of the requirement, I had to also report end index.  Then there was wrap, file parsing, etc...

	int xArr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
	int yArr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

    int matchStartRow = 0;
    int matchEndRow = 0;
    int matchStartCol = 0;
    int matchEndCol = 0;
    for(int x = 0; x < searchLines.size(); x++) //for every word in the word list vector
	{
		bool wordMatches = false;
		for(int i = 0; i < nRowValue; i++) //for every row
		{
			for(int j = 0; j < mColValue; j++) //for every column
			{
				
				for(int dir = 0; dir < 8; dir++) //Line from Geeksforgeeks
				{
					
					// Initialize starting point for current direction 
                    int y = 0; 
    				if(searchLines[x].at(0) == wordMatrix[i][j]) //if the first letter doesn't match, it's not a candidate
    				{
    					std::cout<< "\nSTARTING CANDIDATE: ROW " << i << " col " << j << " letter " << wordMatrix[i][j];
    					int len = searchLines[x].size();
    					int startingRow = i;
    					int startingCol = j;
    					int curRow = i + xArr[dir];
    					int curCol = j + yArr[dir];
    					//The five lines above are taken from geeksforgeeks (with minor modifications)
    				    //y is for the letter of the word
    				    for(y = 1; y < len; y++)
    				    {
    				    	
				            if (curRow >= nRowValue || curRow < 0 || curCol >= mColValue  || curCol < 0) //geeksforgeeks line
				            {
				            	if(!isWrapAround)
				            	{
				            		std::cout << "\nIT'S NOT WRAP AROUND; BREAK FROM THIS";
				            		break; 
				            	}
				            	
				            	else
				            	{
				            		if(curRow == i && curCol == j) //we've wrapped right back to the start
				            		{
				            			std::cout << "We've reached the starting point of row " << i << " col " << j; 
				            			std::cout << "\nChecking to see if we're done with a wraparound guy";
				            			std::cout << "\nValue of y: " << y;
				            			std::cout << "\nValue of len: " << len;
				            			std::cout << "\nWord candidate: " << searchLines[x];
				            			if(y + 1 == len)
				            			{
				            				std::cout << "\nWRAP AROUND MATCH FOUND!!";
				            			}
				            			break;
				            		}
                                    std::cout << "\nAbout to apply wraparound on row " << curRow << " col " << curCol;
				            		if(curRow >= nRowValue)
				            		{
				            			//std::cout << "\ncurRow was " << curRow;
				            			curRow = curRow % nRowValue;
				            			//std::cout << "\ncurRow just wrapped around to " << curRow;
				            		}

				            		if(curRow < 0)
				            		{
				            			//std::cout << "\ncurRow was " << curRow;
				            			curRow = nRowValue + (curRow % nRowValue);
				            			//std::cout << "\ncurRow just wrapped around to " << curRow;
				            		}

				            		if(curCol >= mColValue)
				            		{
				            			//std::cout << "\ncurCol was " << curCol;
				            			curCol = curCol % mColValue;
				            			//std::cout << "\ncurCol just wrapped around to " << curCol;
				            		}

				            		if(curCol < 0)
				            		{
				            			//std::cout << "\ncurColwas " << curCol;
				            			curCol = mColValue + (curCol % mColValue);
				            			//std::cout << "\ncurCol just wrapped around to " << curCol;
				            		}
				            		std::cout << "\nDone with wraparound. New value is row " << curRow << " col " << curCol;
				            	}
				            	
				                
				            }
				  
				            // If not matched,  break 
				            if (wordMatrix[curRow][curCol] != searchLines[x].at(y)) 
				            {
				            	std::cout << "\nTouched char " << wordMatrix[curRow][curCol] << " AND IT'S NOT A MATCH";
				                break; 
				            }
				  
				            //  Moving in particular direction 
				            if(y + 1 != len)
				            {
				            	std::cout << "\nThis is good.  Keep going.";
				                curRow += xArr[dir], curCol += yArr[dir]; //geeksforgeeks line
				                std::cout << "\nWe're about to continue on to checking out row " << curRow << " col " << curCol;
				            }
				            if(y + 1 == len)
				            {
				            	std::cout << "\nMATCH FOUND.  ";
				            	matchStartRow = startingRow;
				            	matchStartCol = startingCol;
				            	matchEndRow = curRow;
				            	matchEndCol = curCol;
				            	
				            	wordMatches = true;
				            	
				            	break;

				            }

				            wordMatches = false;
    				    }

			    	}
			    	
			    }
				
			}
			
			
		}
		if(wordMatches == true)
		{
			std::cout << "(" << matchStartRow << "," << matchStartCol << ")(" << matchEndRow << "," << matchEndCol << ")";
		}
		else
		{
			std::cout << "\nNOT FOUND"; 
		}

	}
    

	return 0;
}
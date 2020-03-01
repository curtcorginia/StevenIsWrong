#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	//1. Handle file parsing.  

	//Three tests I did.  They are the provided no wrap result, the wrap result, and a slightly modified wrap, respectively
    std::ifstream infile("inputtest1.txt");
    //std::ifstream infile("WRAPAROUND.txt");
    //std::ifstream infile("ExtraTest.txt");
    
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
    //Accidental whitespaces were driving me crazy; this was to get rid of null and whitespace
    line.erase(std::find(line.begin(), line.end(), '\0'), line.end());
    line.erase(std::find(line.begin(), line.end(), ' '), line.end());
    if(line == "NO_WRAP")
    {
    	isWrapAround = false;
    }
    else if(line == "WRAP")
    {
    	isWrapAround = true;
    }
    else
    {
    	exit(0);
    }

    std::vector<std::string> searchLines;
    std::getline(infile, line);
    std::istringstream issLineSix(line);
    int searchLineNum = 0;
    issLineSix >> searchLineNum;
    //Put in all the words to search for
    for(int i = 0; i < searchLineNum; i++)
    {
    	std::getline(infile, line);
    	line.erase(std::find(line.begin(), line.end(), '\0'), line.end());
        line.erase(std::find(line.begin(), line.end(), ' '), line.end());
    	searchLines.push_back(line);
    }

    //2. Carry out search
    
	//ES: I liked the way Geeksforgeeks did this.  Two 1D arrays are used to represent the possible directions
	//https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
	//
	//*Lines taken directly from the source above will say //Geeksforgeeks next to them
	//
	//A few differences between their method and mine:
	//	-I started by finding the first matching letter 
	//  -I used a vector of words
	//  -Because of the requirement, I had to also report end index.  Then there was wrap, file parsing, etc...

	int xArr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; //Geeksforgeeks
	int yArr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; //Geeksforgeeks

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
    					int len = searchLines[x].size();
    					int startingRow = i;
    					int startingCol = j;
    					int curRow = i + xArr[dir];
    					int curCol = j + yArr[dir];
    					//The five lines above are taken from geeksforgeeks (with minor modifications)
    				    //y is for the letter of the word
    				    for(y = 1; y < len; y++) //y serves as something like the running length
    				    {
				            if (curRow >= nRowValue || curRow < 0 || curCol >= mColValue  || curCol < 0) //geeksforgeeks line
				            {
				            	if(!isWrapAround)
				            	{
				            		break; 
				            	}
				            	
				            	else
				            	{	
                                    //Mod formulas
                                    //https://codereview.stackexchange.com/questions/57923/index-into-array-as-if-it-is-circular
				            		if(curRow >= nRowValue)
				            		{
				            			curRow = curRow % nRowValue;
				            		}

				            		if(curRow < 0)
				            		{
				            			curRow = nRowValue + (curRow % nRowValue);
				            		}

				            		if(curCol >= mColValue)
				            		{
				            			curCol = curCol % mColValue;
				            		}

				            		if(curCol < 0)
				            		{
				            			curCol = mColValue + (curCol % mColValue);
				            		}			            		
				            	}
				            }
				  
				            // If not matched,  break 
				            if (wordMatrix[curRow][curCol] != searchLines[x].at(y)) 
				            {
				                break; 
				            }
				  
				            //  Moving in particular direction 
				            if(y + 1 != len)
				            {
				            	
				                curRow += xArr[dir], curCol += yArr[dir]; //geeksforgeeks line
				                
				                if(curRow == i && curCol == j) //We've reached the start again after a wraparound
				                {
				                	if(searchLines[x].size() == len) //If size of string equals len, it's one of the "HIGH Edge Cases"
				                	{
				                		break;
				                	}	      
				                	//In the wraparound case, the "stopping condition" is reaching the starting point.
				                	//If this happens, back up by one in whatever direction you came; the one exception
				                	//is an edge case like the example "HIGH", where you end where you started.  The if
				                	//above takes care of that edge case      			
			            			matchStartRow = startingRow;
			            			matchStartCol = startingCol;	            			
			            			matchEndRow = curRow - xArr[dir]; //back it up
			            			matchEndCol = curCol - yArr[dir]; //back it up	         			
			            			wordMatches = true;
			            			break;			            			
				                }
				            }
				            //This is the "traditional" match case.  We've simplify found the word; we didn't wrap to start
				            if(y + 1 == len) //Geeksforgeeks
				            {
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
		//At long last, take care of printing
		if(wordMatches == true)
		{
			std::cout << "\n";
			std::cout << "(" << matchStartRow << "," << matchStartCol << ")(" << matchEndRow << "," << matchEndCol << ")";
		}
		else
		{
			std::cout << "\nNOT FOUND"; 
		}
	}
	return 0;
}
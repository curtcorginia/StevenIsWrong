#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//#include <bits/stdc++.h> 
#include <iomanip> 
#include <iostream> 
#include <cmath> 
#include <cstdlib>

struct Coordinate
{
	int coorNum;
	double xVal;
	double yVal;
	double zVal;
};

//Helper Function/formula taken from geeksforgeeks, with slight modifications
//https://www.geeksforgeeks.org/program-to-calculate-distance-between-two-points-in-3-d/
bool checkIfNeighbors(double x1, double y1,  
            double z1, double x2,  
            double y2, double z2, double radius) 
{ 
    double d = sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) +  
                pow(z2 - z1, 2) * 1.0); 
    if(d <= radius)
    {
    	return true;
    }
    else
    {
    	return false;
    }
    return false; 
} 

int main()
{
	std::ifstream infile("neighbors1.txt");
	std::string line;
	int radius = 0;
	int numLocations = 0;
	std::getline(infile, line);

    std::istringstream issLineOne(line);
        
    issLineOne >> radius;
    std::getline(infile, line);
    std::istringstream issLineTwo(line);
    
    issLineTwo >> numLocations;
    std::vector<Coordinate> allCoordinates;
    //Read into a vector, as you have to check the values multiple times
    for(int i = 0; i < numLocations; i++)
    {
    	std::getline(infile, line);
    	std::stringstream coorStream(line);
    	int coorNum;
    	double xVal;
    	double yVal; 
    	double zVal;
    	coorStream >> coorNum >> xVal >> yVal >> zVal;
    	Coordinate thisCoordinate;
    	thisCoordinate.coorNum = coorNum;
    	thisCoordinate.xVal = xVal;
    	thisCoordinate.yVal = yVal;
    	thisCoordinate.zVal = zVal;
    	allCoordinates.push_back(thisCoordinate);
    }

    //For every coordinate, check everything in the vector except itself to see if it's a neighbor
    int p = 1;
    for(int i = 0; i < numLocations; i++)
    {
    	Coordinate pivotCoordinate = allCoordinates[i]; //I'm calling the coordinate we're comparing to everything the "pivot"
    	int neighborCount = 0;
    	std::vector<int> matchList;
    	for(int j = 0; j < numLocations; j++)
    	{
    		if(i != j)
    		{
    			
    		    Coordinate neighborCoordinate = allCoordinates[j];
    		    int pivotNum = allCoordinates[i].coorNum; //it's 1-based, so that's just i + 1
    		    double pivotX = allCoordinates[i].xVal;
    		    double pivotY = allCoordinates[i].yVal;
    		    double pivotZ = allCoordinates[i].zVal;
    		    int neighborNum = allCoordinates[j].coorNum;
    		    double neighborX = allCoordinates[j].xVal;
    		    double neighborY = allCoordinates[j].yVal;
    		    double neighborZ = allCoordinates[j].zVal;
    		    
    		    if(std::abs(pivotX - neighborX)> radius)
    		    {
    		        //don't bother 
    		    }
    		    else if(std::abs(pivotY - neighborY)> radius)
    		    {
    		        //don't bother
    		    }
    		    else if(std::abs(pivotZ - neighborZ)> radius)
    		    {
    		        //don't bother
    		    }
				else
				{
	    		    if(checkIfNeighbors(pivotX, pivotY, pivotZ, neighborX, neighborY, neighborZ, radius))
	    		    {
	    		        matchList.push_back(allCoordinates[j].coorNum);
	    		        neighborCount++;
	    		    }
	    		}
    	    }
    	    else
    	    {
    	    	//keep going, but ignore that one
    	    }
    	}
    	
    	std::cout << "\n#" << p;
    	std::cout << "["<< neighborCount;
    	for(int x = 0; x < matchList.size(); x++)
    	{
    		std::cout << "," << matchList[x];
    		
    	}
    	p++;
    	std::cout << "]";
    }
    std::cout << "]";



	return 0;
}
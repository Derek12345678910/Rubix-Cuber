#include "../main.h"
#include "../cube.h"

// Controls the cube itself

// Function to get row and column from a linear index
pair<int, int> squareReturn(int index)
{
    int row = index / 3;
    int col = index % 3;
    return make_pair(row, col);
}

// Constructor
cube::cube(const char* information){

    int index = 0; // To track the index in the 1D information array

    // loop through the faces and grab information from each face
    for (int face = 0; face < 6; ++face)
    {
        for (int i = 0; i < 9; ++i)  // 9 squares per face
        {
            auto [row, col] = squareReturn(i);  // Get row and col from the index
            faces[face][row][col] = new char; // Allocate memory
            *faces[face][row][col] = information[index++];  // Assign character
        }
    }

    // Using the information create edges and corners to store

    
}

// Destructor
cube::~cube(){
    // Destroy cube information
    int index = 0; // To track the index in the 1D information array

    // loop through the faces and grab information from each face
    for (int face = 0; face < 6; ++face)
    {
        for (int i = 0; i < 9; ++i)  // 9 squares per face
        {
            auto [row, col] = squareReturn(i);  // Get row and col from the index
            delete faces[face][row][col]; // deletes the value one by one
        }
    }
}



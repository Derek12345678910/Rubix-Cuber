#include "../main.h"
#include "../cube.h"

// Function to get row and column from a linear index
pair<int, int> squareReturn(int index)
{
    int row = index / 3;
    int col = index % 3;
    return make_pair(row, col);
}

// Function find the key using the value // ONLY FOR CHAR
int findKey(const map<char, char> m, char value) {
    for (const auto& pair : m) {
        if (pair.second ==  value) {
            return pair.first;  // Return the key if the value matches
        }
    }
    return -1;  // Return -1 if the value is not found
}

// Constructor
cube::cube(const char* information){

    int index = 0; // To track the index in the 1D information array

    // loop through the faces and grab information from each face
    for (int face = 0; face < 6; ++face)
    {
        //cout << '\n' << face << ": ";
        for (int i = 0; i < 9; ++i)  // 9 squares per face
        {
            auto [row, col] = squareReturn(i);  // Get row and col from the index
            facesInput[face][row][col] = new char; // Allocate memory
            *facesInput[face][row][col] = information[index++];  // Assign character
            //cout << row << " " << col << " " << facesInput[face][row][col] << " ";
        }
    } // COMPLETE

    // create cube object
    Cube* cubeObj = new Cube;
    cuber = cubeObj;
    // distinguish top - bottom - front - back
    for(int face = 0; face < 6; ++face){ // find the middle of each face and assign each to a direction
        //cout << "\n" << face << ": ";
        auto[row, col] = squareReturn(4); // return the middle of the face --> 5-1 because its center / arry
        cuber->cubeFaces[cuber->faceValues[face]] = *facesInput[face][row][col]; // Set cubeFace map
        //auto test = cuber->cubeFaces.find(cuber->faceValues[face]);
        //cout << test->first << " " << test->second << " ";
    } // COMPLETE

    // Create 8 corners 
    for(int i = 0; i < 8; ++i){
        Corner* corner = new Corner; // create corner object
        corner->position = i; // set position

        auto[row, col] = squareReturn(cuber->cornerValues[i % 4]); // return corner values as [row, col]
        auto[mid1, mid2] = squareReturn(4); // middle of square
        int colIndex = 0; // used for the colour // is just the index of d
        // we do not know which face the corner is, so we must compare the faces it should have with the actual faces, and when we do we know which
        for(auto d : cuber->cornerPos[i]){ // loop the dimensions for the certain corner
            for(int face = 0; face < 6; ++face){ // loop all faces on the cube
                if(*facesInput[face][mid1][mid2] == cuber->cubeFaces[d]){ // if the dimension matches the face, WE ARE ON THE CORRECT FACE
                    corner->colors[colIndex] = *facesInput[face][row][col]; // set the colour
                    // Orientation
                    auto cornerCol = cuber->cubeFaces.find(findKey(cuber->cubeFaces, corner->colors[colIndex])); // find the side the face is supposed to be on
                    auto comparedCol = cuber->cubeFaces.find(findKey(cuber->cubeFaces, *facesInput[face][mid1][mid2]));
                    if(cornerCol->first == 'T' || cornerCol->first == 'O'){ // Only use top or bottom
                        // if the corner pieces top - bottom is facing front - back the orientation --> 1
                        if(comparedCol->first == 'F' || comparedCol->first == 'B'){
                            corner->orientation = 1;
                        }
                        // if the corner pieces top - bottom is NOT facing front - back the orientation is --> 2
                        if(comparedCol->first == 'L' || comparedCol->first == 'R'){
                            corner->orientation = 2;
                        }
                        // if piece is perfect orientation is --> 0
                        if(comparedCol->first == 'T' || comparedCol->first == 'O'){
                            corner->orientation = 0;
                        }
                    } 
                }
            } 
            colIndex ++;        
        }
        // Assign corner to an array of corner holders
        corners[i] = corner;
        /*
        cout << "Position: " << corner->position << endl;
        cout << "Orientation: " << corner->orientation << endl;
        cout << "Colour 1: " << corner->colors[0] << " Colour 2: " << corner->colors[1] << " Colour 3: " << corner->colors[2] << endl;
        */
    } // COMPLETE

    // Create 12 edges
    for(int i = 0; i < 12; ++i){
        Edge* edge = new Edge; // create edge object
        edge->position = i; // set position
        auto[row, col] = squareReturn(cuber->edgeValues[i % 4]); // return corner values as [row, col]
        auto[mid1, mid2] = squareReturn(4); // middle of square
        int colIndex = 0; // used for the colour // is just the index of d
        // we do not know which face the edge is, so we must compare the faces it should have with the actual faces, and when we do we know which
        for(auto d : cuber->edgePos[i]){ // loop the dimensions for the certain corner
            for(int face = 0; face < 6; ++face){ // loop all faces on the cube
                if(*facesInput[face][mid1][mid2] == cuber->cubeFaces[d]){ // if the dimension matches the face, WE ARE ON THE CORRECT FACE
                    edge->colors[colIndex] = *facesInput[face][row][col]; // set the colour
                     // Orientation
                    auto cornerCol = cuber->cubeFaces.find(findKey(cuber->cubeFaces, edge->colors[colIndex])); // find the side the face is supposed to be on
                    auto comparedCol = cuber->cubeFaces.find(findKey(cuber->cubeFaces, *facesInput[face][mid1][mid2]));
                    if(cornerCol->first == 'T' || cornerCol->first == 'O'){ // Only use top or bottom
                        // if the top - bottom piece is not facing top - bottom orientation --> 1
                        if(comparedCol->first == 'F' || comparedCol->first == 'B'){
                            edge->orientation = 1;
                        }
                        // if piece's top - bottom is facing top - bottom orientation --> 0
                        if(comparedCol->first == 'L' || comparedCol->first == 'R'){
                            edge->orientation = 2;
                        }
                    }
                    
                }
            }
            colIndex ++;
        }
        edges[i] = edge;
        /*
        cout << "Position: " << edge->position << endl;
        cout << "Orientation: " << edge->orientation << endl;
        cout << "Colour 1: " << edge->colors[0] << " Colour 2: " << edge->colors[1] << endl;
        */
    }   
}

// Destructor
cube::~cube(){

    // destroy face information
    for (int face = 0; face < 6; ++face) // loop through the faces and grab information from each face
    {
        for (int i = 0; i < 9; ++i)  // 9 squares per face
        {
            auto [row, col] = squareReturn(i);  // Get row and col from the index
            delete facesInput[face][row][col]; // deletes the value one by one
        }
    }

    // Delete corner pointers
    for (int i = 0; i < 8; ++i) {
        delete corners[i];  // Delete each corner pointer
    }

    // Delete edge pointers
    for (int i = 0; i < 12; ++i) {
        delete edges[i];  // Delete each edge pointer
    }

    // delete cube object
    delete cuber; 

}



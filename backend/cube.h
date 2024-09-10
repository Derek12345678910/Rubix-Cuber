#ifndef cube_h
#define cube_h

// standard libraries
#include <map>

// standard library
using namespace std;

// create a structure of the cube
struct Cube{
    // Side, Colour
    map<char, char> cubeFaces; // Tells us which colour is which part of a fixed cube
    /* Numbering of face sides goes from
    Top --> 0 --> T 
    Bottom --> 1 --> O
    Back --> 2 --> B
    Front --> 3 -- F
    Left --> 4 --> L
    Right --> 5 --> R
    */
    char faceValues[6] = {'T', 'O', 'B', 'F', 'L', 'R'}; // array of side types in order

    /* Corner Positions --> the corner number and the corresponding sides they are located on
    0 --> Top, Back, Left
    1 --> Top, Back, Right
    2 --> Top, Front, Left
    3 --> Top, Front, Right
    4 --> Bottom, Back, Left
    5 --> Bottom, Back, Right
    6 --> Bottom, Front, Left
    7 --> Bottom, Front, Right
    */
   int cornerValues[4] = {0, 2, 6, 8}; // array of all corner pieces on a face
   map<int, vector<char>> cornerPos = {
    {0, {'T', 'B', 'L'}},  // 0: Top, Back, Left
    {1, {'T', 'B', 'R'}},  // 1: Top, Back, Right
    {2, {'T', 'F', 'L'}},  // 2: Top, Front, Left
    {3, {'T', 'F', 'R'}},  // 3: Top, Front, Right
    {4, {'B', 'B', 'L'}},  // 4: Bottom, Back, Left
    {5, {'B', 'B', 'R'}},  // 5: Bottom, Back, Right
    {6, {'B', 'F', 'L'}},  // 6: Bottom, Front, Left
    {7, {'B', 'F', 'R'}}   // 7: Bottom, Front, Right
    };

    /* Edge positions --> the edge number and the corresponding sides they are located on
    0 --> Top, Front
    1 --> Top, Right
    2 --> Top, Back
    3 --> Top, Left
    4 --> Bottom, Front
    5 --> Bottom, Right
    6 --> Bottom, Back
    7 --> Bottom, Left
    8 --> Front, Right
    9 --> Front, Left
    10 --> Back, Right
    11 --> Back, Left
    */
   int edgeValues[4] = {1, 3, 5, 7}; // array of all edge pieces on a face
   map<int, vector<char>> edgePos = {
    {0, {'T', 'F'}},  // 0: Top, Front
    {1, {'T', 'R'}},  // 1: Top, Right
    {2, {'T', 'B'}},  // 2: Top, Back
    {3, {'T', 'L'}},  // 3: Top, Left
    {4, {'B', 'F'}},  // 4: Bottom, Front
    {5, {'B', 'R'}},  // 5: Bottom, Right
    {6, {'B', 'B'}},  // 6: Bottom, Back
    {7, {'B', 'L'}},  // 7: Bottom, Left
    {8, {'F', 'R'}},  // 8: Front, Right
    {9, {'F', 'L'}},  // 9: Front, Left
    {10, {'B', 'R'}}, // 10: Back, Right
    {11, {'B', 'L'}}  // 11: Back, Left
    };
};

// creates a structure of the cubes edges
struct Edge {
    int position;     // where the edge is located (0-11)
    int orientation;  // flipped or not (0 or 1)
    char colors[2];   // the two colors of the edge piece
};

// creates a structure of the cubes corners
struct Corner {
    int position;     // where the corner is located (0-7)
    int orientation;  // rotation state (0, 1, or 2)
    char colors[3];   // the three colors of the corner piece
};

// store the cubes faces and information in a structure
class cube
{   
public:

    // raw cube information
    char* facesInput[6][3][3];

    // solving cube information
    Corner* corners[8]; // holds all corners
    Edge* edges[12]; // holds all edges
    Cube* cuber = nullptr; // holds the current cube we are working on

    // constructor
    cube(const char* information); // points to information given

    // destructor
    ~cube();
};

#endif
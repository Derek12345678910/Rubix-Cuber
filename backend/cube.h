#ifndef cube_h
#define cube_h

// standard libraries


// standard library
using namespace std;

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
    char* faces[6][3][3];

    // solving cube information
    

    // constructor
    cube(const char* information); // points to information given

    // destructor
    ~cube();
};

#endif
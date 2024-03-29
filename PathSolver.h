#ifndef COSC_ASSIGN_ONE_PATHSOLVER
#define COSC_ASSIGN_ONE_PATHSOLVER

#include "Node.h"
#include "NodeList.h"
#include "Types.h"

class PathSolver
{
public:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    // Constructor/Destructor
    PathSolver();
    ~PathSolver();

    // Execute forward search algorithm
    // To be implemented for Milestone 2
    void forwardSearch(Env env);

    // Get a DEEP COPY of the explored NodeList in forward search
    // To be implemented for Milestone 2
    NodeList *getNodesExplored();

    // Execute backtracking and Get a DEEP COPY of the path the
    // robot should travel
    // To be implemented for Milestone 3
    NodeList *getPath(Env env);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

private:
    /*                                           */
    /* DO NOT MOFIFY THESE VARIABLES             */
    /*                                           */

    // Nodes explored in forward search algorithm
    NodeList *nodesExplored;

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */
    Node *startNode;
    Node *goalNode;
    Node *currentNode;
    Node *nodeUp;
    Node *nodeDown;
    Node *nodeLeft;
    Node *nodeRight;
    NodeList *neighbors;
    NodeList *openList;
    NodeList *path;

    //Sets up pointers to nodes and updates lists
    void initializeAlgoVars(Env env);

    //Sets node(up,down,left,right) pointers to
    //New nodes in each direction
    void pointAllDirections();

    //Adds nodes to openList if maze co-ord is empty
    //If not, then deletes node.
    void addAllDirections(Env env);

    //Called by addAllDirections to add node to openlist
    void addElementIfEmpty(Node *node, Env env);

    //Sets neighbours list that is used by getPath
    void createNeighborsList(Env env);

    //Called by createNeighborsList to add nodes to
    //neighbors list.
    void addAllDirections2(Env env);

    //Called by addAllDirections2 to add node to neighbors list
    void addElementIfEmpty2(Node *node, Env env);
};

#endif //COSC_ASSIGN_ONE_PATHSOLVER
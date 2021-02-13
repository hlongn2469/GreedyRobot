//GreedyRobot.h
//CSS 342 Program2
//Implemented by Kray Nguyen on 11/2/2020
#ifndef G_R
#define G_R
#include <string>
#include "Point.h"
using namespace std;

// The class models the robot paths towards the treasure 
class GreedyRobot {
public:
    Point North;
    Point South;
    Point West;
    Point East;
private:
    int NumPaths(Point Robot, Point Treasure, string path_str, int max_distance, string previous_direction, int shortest_p_distance, Point ShortestCoordinates);
    int CountConsecutives(string path_str);
    int x_robot;
    int y_robot;
    int x_treasure;
    int y_treasure;

    // coordinates between robot and treasure based on the formula in the description:
    // (x_treasure - x_robot, y_treasure - y_robot)
    Point ShortestCoordinates;
    Point Robot;
    Point Treasure;

    // total of steps/moves that the robot needs to move to reach the treasure
    int shortest_p_distance;
    int max_distance;
    int num_paths;
    string path_str;
    string previous_direction;
};
#endif

//GreedyRobot.cpp
//CSS 342 Program2
//Implemented by Kray Nguyen on 11/2/2020
#include "GreedyRobot.h"
#include "Point.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

// implementation of recursive program that determines all unique shortest possible paths 
// from the Robot to the Treasure with the following stipulation: The Robot may never move
// in the same direction more than a MaxDistance times in a row.

// helper method that returns the most consecutives directions in the path
int CountConsecutives(string path_str){
    int largest_count = 0;
    int count_ = 1;
    for(int i = 1; i < path_str.length() + 1; i++){
        if(path_str[i - 1] == path_str[i]){
            count_++;
        } else {
            if(count_ > largest_count){
                largest_count = count_;
            }
            count_ = 1;
        }
    }
    return largest_count;
}

// Returns total valid number of paths to get to the Treasure using recursion
// for each recursive call, the position of the Robot and other helper values to determine path validness is updated
// Point class helps to update the Robot position
int NumPaths(Point Robot, Point Treasure, string path_str, int max_distance, string previous_direction, int shortest_p_distance, Point ShortestCoordinates){
    path_str += previous_direction;

    Point North(0,1);
    Point South(0,-1);
    Point East(1,0);
    Point West(-1,0);

    if(path_str.length() > shortest_p_distance){
        return 0;
    } else if(Robot == Treasure && (CountConsecutives(path_str) <= max_distance)){
        cout << path_str << endl;
        return 1;
    } else {
        // Evaluate x and y coordinates between Robot and Treasure and decide to: recursively go northeast 
        if(ShortestCoordinates.getX() > 0 && ShortestCoordinates.getY() > 0){
            return NumPaths(Robot + North ,Treasure, path_str, max_distance, "N", shortest_p_distance, ShortestCoordinates) + NumPaths(Robot + East,Treasure,path_str, max_distance, "E", shortest_p_distance, ShortestCoordinates);
        } // recursively go southeast 
        else if (ShortestCoordinates.getX() > 0 && ShortestCoordinates.getY() < 0){
            return NumPaths(Robot + South ,Treasure,path_str, max_distance, "S", shortest_p_distance, ShortestCoordinates) + NumPaths(Robot + East,Treasure,path_str, max_distance, "E", shortest_p_distance, ShortestCoordinates);
        } // recursively go SouthWest
        else if (ShortestCoordinates.getX() < 0 && ShortestCoordinates.getY() < 0){
            return NumPaths(Robot + South ,Treasure, path_str, max_distance, "S", shortest_p_distance, ShortestCoordinates) + NumPaths(Robot + West,Treasure, path_str, max_distance, "W", shortest_p_distance,ShortestCoordinates);
        } // recursively go northwest
        else if (ShortestCoordinates.getX() < 0 && ShortestCoordinates.getY() > 0 ){
            return NumPaths(Robot + North ,Treasure, path_str, max_distance, "N", shortest_p_distance, ShortestCoordinates) + NumPaths(Robot + West,Treasure, path_str, max_distance, "W", shortest_p_distance, ShortestCoordinates);
        }
    }
    return 0;
}

int main(int argc, char *argv[]){
    int x_robot = atoi(argv[1]);
    int y_robot = atoi(argv[2]);
    Point Robot(x_robot, y_robot);

    int x_treasure = atoi(argv[3]);
    int y_treasure = atoi(argv[4]);
    Point Treasure(x_treasure, y_treasure);

    int max_distance = atoi(argv[5]);

    Point ShortestCoordinates = Treasure - Robot;
    int shortest_p_distance = abs(ShortestCoordinates.getX()) + abs(ShortestCoordinates.getY());

    string path_str = "";
    string previous_direction = "";

    if(Robot == Treasure){
        cout << "Number of Paths: 0" << endl;
    } else {
        int num_paths = NumPaths(Robot, Treasure, path_str, max_distance, previous_direction, shortest_p_distance, ShortestCoordinates);
        cout << "Number of Paths: " << num_paths << endl;
    }
    return 0;
}

#include "point.h"

double get_distance(Point a, Point b)
{
  return sqrt( pow((a.x - b.x),2)+pow((a.y - b.y),2));
}

void get_closest_food(Point food_points[], int points_length, Point current_location, Point *closest_food_location)
{
  double distance = get_distance(current_location,food_points[0]);
  *closest_food_location = food_points[0];
  LOOPS(1,points_length)
  {
    double current_distance = get_distance(current_location,food_points[i]);
    if(current_distance < distance)
    {
      distance = current_distance;
      *closest_food_location = food_points[i];
    }
  }
}
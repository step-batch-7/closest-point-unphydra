#include "point.h"

double get_distance(Point a, Point b)
{
  double dx = pow((a.x - b.x),2);
  double dy = pow((a.y - b.y),2);
  return sqrt(dx+dy);
}

void get_closest_food(Point food_points[], int points_length, Point current_location, Point *closest_food_location)
{
  double distance = get_distance(current_location,food_points[0]);
  closest_food_location->x = food_points[0].x;
  closest_food_location->y = food_points[0].y;
  for (int i = 1; i < points_length; i++)
  {
    double current_distance = get_distance(current_location,food_points[i]);
    if(current_distance < distance)
    {
      distance = current_distance;
      closest_food_location->x = food_points[i].x;
      closest_food_location->y = food_points[i].y;
    }
  }
}
#include <iostream>
#include <math.h>
using namespace std;


float PaintHouse (int width, int depth, int windows){
    int perimeter = 2 * (width+depth);
    if (width<0 || windows<0 || depth<0){
        return -1;
    }
    else if (perimeter == 0){
        double cost = 0;
        float finalCost = cost + windows*6.75;
        return finalCost;
    }
    else if ( perimeter > 0 && perimeter <= 100){
        double cost = perimeter * 8;
         float finalCost = cost + windows*6.75;
         return finalCost;
    }
    else if (perimeter > 100 && perimeter <= 200 ){
        double cost = (100*8) + (perimeter-100)*10;
        float finalCost = cost + windows*6.75;
        return finalCost;
    }
    else if (perimeter>200){
        double cost = (100*8) + (100)*10 + (perimeter-200)*15;
    float finalCost = cost + windows*6.75;
    return finalCost;
    }
}
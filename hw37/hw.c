/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.c
 * Description: Reads two 2D points from the user and calculates their midpoint.
 * Date:        2026-04-23
 ******************************************************************************/

#include <stdio.h>

int main() {
    double x1, y1, x2, y2;

    // The spaces in the formatting string tell scanf to ignore any 
    // leading whitespace or newlines between the coordinates.
    scanf(" (%lf,%lf) (%lf,%lf)", &x1, &y1, &x2, &y2);

    // Calculate the midpoint
    double mid_x = (x1 + x2) / 2.0;
    double mid_y = (y1 + y2) / 2.0;

    // Output with default 6 decimal places to match the sample run
    printf("(%f,%f)\n", mid_x, mid_y);

    return 0;
}
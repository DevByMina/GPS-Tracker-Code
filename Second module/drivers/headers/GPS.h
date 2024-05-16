//Ahmed Khedr

#ifndef GPS_h
#define GPS_h

#include "math.h"
#include "stdlib.h"
#include "UART.h"
#define pi 3.14159265358979323846

double deg2rad(double deg);
double rad2deg(double rad);
double distance(double lat1, double lon1, double lat2, double lon2);
void lineparsing(void);
void getinfo(char contents[5][20]);

#endif

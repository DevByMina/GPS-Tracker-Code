//Ahmed Khedr

#include "../headers/GPS.h"

char contents[7][20]={'\0'};
extern float prevlat;
extern float prevlong;
extern float currentlat;
extern float currentlong;
extern float templat;
extern float templong;


double deg2rad(double deg) {
  return ((double)deg * pi / 180.0f);
}

double rad2deg(double rad) {
  return ((double)rad*180.0f/pi);
}
double distance(double lat1, double lon1, double lat2, double lon2) {
  double theta, dist;
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
  else {
    theta = lon1 - lon2;
    dist = (double)sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = (double)acos(dist);
    dist = (double)rad2deg(dist);
    dist = dist * 60 * 1.1515f;
    dist = dist * 1.609344f*1000;
    return (dist);
  }
}

void lineparsing(void){//117 bytes
    char flag=1;
    char content;
    char elements=0;
    char column=0;
    char encounter;
    unsigned char x;
    while(flag==1){
        encounter=0;
        x=UART_inChar2();
        if(x=='$'){
            x=UART_inChar2();
            if(x=='G'){
                x=UART_inChar2();
            if(x=='P'){
                x=UART_inChar2();
            if(x=='R'){
                x=UART_inChar2();
            if(x=='M'){
                x=UART_inChar2();
            if(x=='C'){//4 tabs
                //logic hna h5lih yfdl y3di l8ait ma y2abl 2 mn ',' b3dha y2ra al hrf alli b3dha lw A f tmm 5d al ba2i
                //b3dha y5li al flag b zero m3nha kda khlas 5lst w 5dt point sh
                //  UART_outChar0('>');
                while(encounter<2){
                    // 408ltha anha 3mla t7r2 l8ait ma twsl ll check char
                     x=UART_inChar2();
                   if(x==','){encounter++;}}
                     x=UART_inChar2();
           if(x=='A'){

                        x=UART_inChar2();
                      for(elements=0;elements<7;elements++){
                            column=0;
                            for(column=0;column<20;column++){
                                  content=UART_inChar2();
                                    if(content==','){break;}
                                    if(content==' '){content=UART_inChar2();}
                                        contents[elements][column]=content;
                                    //  UART_outChar0(contents[elements][column]);}}
                //UART_outChar0('#');
                     flag=0;}}}}}}}}}}
	templat = atof(contents[0]);
	currentlat=((int)templat/100);
	currentlat+=(templat-(currentlat*100))/60;
	templong = atof(contents[2]);
	currentlong=((int)templong/100);
	currentlong+=(templong-(currentlong*100))/60;
}

void getinfo(char contents[5][20]){
  char row;
    char column;
    for(row=0;row<5;row++){
       for(column=0;column<20;column++){
             UART_outChar0(contents[row][column]);
         }
         UART_outChar0(' ');
     }

}

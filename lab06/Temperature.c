#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ifttt.h"
int main(int argc, char *argv[])
{
 FILE *fd;
 int n,y,h,l,first,last;
 char Buffer[101];
 char *temp;
 char Low[50], Current[50],High[50];
 time_t start = time(NULL);
 int next = start+1;
 first =0;
 while(start < next){
 if((fd = fopen("/sys/bus/w1/devices/28-021313bdc5aa/w1_slave", "r")) == (FILE *)NULL) {
 perror("Error: Failed to Open w1_slave file");
 (void) exit(1);
 }
 n = fread(Buffer, 1, 100, fd);
 if(n == 0) {
 perror("Error: No Arguments Found");
 exit(1);
 }
 Buffer[n] = '\0';
 fprintf(stdout, "Read '%s'\n",Buffer+69);
 (void) fclose(fd);
 temp = Buffer+69;
 printf("Temp: %s",temp);
 y = atoi(temp);
 printf("Integer Y: %d\n",y);
 if(first == 0){
	l = y;
	h = y;
	first =1;
	last = y;
	sprintf(Low,"Lowest Temp: %d C",low/1000);
	sprintf(Current,"Current Temp: %d C",y/1000);
	sprintf(High,"Highest Temp: %d C",high/1000);
	ifttt("https://maker.ifttt.com/trigger/temp_change/with/key/qUjk5_1YTEvBRpXGUmjd4", l,cur, h);
	}
 else{
	if(y <low){low = y;}
	else if(y>high){high = y;}
	else if(((last-low)>=1000) ||((high-last)>=1000)){
	sprintf(Low,"Lowest Temp: %d C",low/1000);
        sprintf(Current,"Current Temp: %d C",y/1000);
        sprintf(High,"Highest Temp: %d C",high/1000);
	  ifttt("https://maker.ifttt.com/trigger/temperature_change/with/key/ZcEJrD-0bp1Br7ZXYE_md", l,cur, h);
	  last = y;
	}
	
	}
 printf("High: %d Current: %d Low: %d\n",high,y,low);
 start = time(NULL);
 next = start+1;
}
 return 0;
}

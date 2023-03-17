

/* Description:
 * This code displays the shortest path one can take from one city to another city in the netherlands.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*EVERY CITY IS ASSOCIATED WITH A NUMBER*/
#define AMSTERDAM 0
#define DEN_HAAG 1
#define EINDHOVEN 2
#define ENSCHEDE 3
#define GRONINGEN 4
#define ZWOLLE 5
#define LEEUWARDEN 6
#define MAASTRICHT 7
#define MEPPEL 8
#define NIJMEGEN 9
#define UTRECHT 10
#define DEN_HELDER 11

#define STOPS 12		//TOTAL NUMBER OF STOPS
#define INFINITY 9999

/*GIVEN A NUMBER WILL GIVE ITS CITY*/
void reIdentify(int stop){		
	switch(stop){
		case AMSTERDAM:
			printf("Amsterdam\n");
			return;
		case DEN_HAAG:
			printf("Den Haag\n");
			return;
		case EINDHOVEN:
			printf("Eindhoven\n");
			return;
		case ENSCHEDE:
			printf("Enschede\n");
			return;
		case GRONINGEN:
			printf("Groningen\n");
			return;
		case ZWOLLE:
			printf("Zwolle\n");
			return;
		case LEEUWARDEN:
			printf("Leeuwarden\n");
			return;
		case MAASTRICHT:
			printf("Maastricht\n");
			return;
		case MEPPEL:
			printf("Meppel\n");
			return;
		case NIJMEGEN:
			printf("Nijmegen\n");
			return;
		case UTRECHT:
			printf("Utrecht\n");
			return;
		case DEN_HELDER:
			printf("Den Helder\n");
			return;
	}
}

/*GIVEN A CITY WILL GIVE ITS NUMBER*/
int identify(char *city){
	if(strcmp("Amsterdam", city)==0){
			return AMSTERDAM;
	} else if(strcmp("Den Haag", city)==0){
			return DEN_HAAG;
	} 	else if(strcmp("Eindhoven", city)==0){
			return EINDHOVEN;
	} 	else if(strcmp("Enschede", city)==0){
			return ENSCHEDE;
	} 	else if(strcmp("Groningen", city)==0){
			return GRONINGEN;
	} 	else if(strcmp("Zwolle", city)==0){
			return ZWOLLE;
	} 	else if(strcmp("Leeuwarden", city)==0){
			return LEEUWARDEN;
	} 	else if(strcmp("Maastricht", city)==0){
			return MAASTRICHT;
	} 	else if(strcmp("Meppel", city)==0){
			return MEPPEL;
	} 	else if(strcmp("Nijmegen", city)==0){
			return NIJMEGEN;
	} 	else if(strcmp("Utrecht", city)==0){
			return UTRECHT;
	} 	else if(strcmp("Den Helder", city)==0){
			return DEN_HELDER;
	} 
	return 0;		
}

/*WILL FIND THE SHORTEST PATH FROM ONE CITY TO ANOTHER USING DIJKSTRAS ALGORITHM*/
void pathFinder(int map[STOPS][STOPS], int start, int end){
	int previous[100] = {0};		//keeps track of which node was previous before going to the current one
	int time[STOPS][STOPS] = {0};	//time table that gets initialized to infinity for unreachable stops
	int distance[100] = {0};	//array that keeps track of time it takes to travel between nodes
	int visited[STOPS] = {0};	//array that tracks which nodes have been visited
	int tracker=0; //basic tracker for a loop
	int min=INFINITY; //tracks which node has the lowest time value
	int next=-1; //keeps track of the next shortest path to visit
	int current=-1;	//keeps track of current node1
	int target=-1;		//keeps track of end node
	int solutions[STOPS] = {0};	//array for organizing solutions for printing
	int unreachable=0;		//tracker to check if a path cannot be taken
	
	/*SETS ALL UNKNOWN VALUES TO INFINITY OR TO TIME IT TAKES TO TRAVEL*/
	for(int i=0; i<STOPS; i++){
		for(int j=0; j<STOPS; j++){
			if(map[i][j]==0){
				time[i][j]=INFINITY;
			} else {
				time[i][j]=map[i][j];
			}
		}
	}
	
	/*INITIALIZES ARRAYS*/
	for(int i=0; i<STOPS; i++){
		visited[i]=0;
		distance[i]=INFINITY;
		previous[i]=-1;
	}
	
	current=start;
	/*DISTANCE TO ITSELF IS 0*/
	distance[current]=0;
	/*DIJKSTRAS ALGORITHM IMPLEMENTATION*/
	for(int j=0; j<STOPS; j++){
		visited[current]=1;
		min=INFINITY;
		for(int i=0;i<STOPS;i++){
			if(!visited[i] && distance[current]+time[current][i]<distance[i]){
				distance[i]=distance[current]+time[current][i];
				previous[i]=current;
			}
		}
		for(int i=0; i<STOPS; i++){
			if(!visited[i] && distance[i]<min){
				min=distance[i];
				next=i;
			}
		}
		current=next;
		if(visited[end]==1){
			break;
		}
	}

	target=end;

	/*INITIALIZE TEMPORARY SOLUTION ARRAY*/
	for(int i=0; i<STOPS; i++){
		solutions[i]=-1;
	}
	
	int end1=end;
	
	/*CHECKS IF THE STOP CAN BE REACHED*/
	for(int i=0; previous[end1]!=start; i++){
		if(distance[end1]==INFINITY){
			unreachable=1;
			printf("UNREACHABLE\n");
			break;
		}
		end1=previous[end1];
		if(previous[end1]==-1){
			printf("UNREACHABLE\n");
			unreachable=1;
			break;
		}
	}
	
	if(unreachable==0){	
		/*MAKES AN ARRAY OF WHICH STOPS HAVE BEEN VISITED*/
		for(int i=0;previous[end]!=start; i++){
			solutions[i]=previous[end];
			end=previous[end];
			tracker++;
		}
		
		reIdentify(start);
		
		for(;tracker>=0;tracker--){
			reIdentify(solutions[tracker]);
		}
	
		reIdentify(target);
	
		printf("%d\n", distance[target]);
		return;
	}
}
	
int main(int argc, char **argv){

	int map[STOPS][STOPS];
	
	/*MAP OF ALL CONNECTIONS WITH TIMES*/
	
	map[AMSTERDAM][AMSTERDAM]=0;
	map[AMSTERDAM][DEN_HAAG]=46;
	map[AMSTERDAM][EINDHOVEN]=0;
	map[AMSTERDAM][ENSCHEDE]=0;
	map[AMSTERDAM][GRONINGEN]=0;
	map[AMSTERDAM][ZWOLLE]=0;
	map[AMSTERDAM][LEEUWARDEN]=0;
	map[AMSTERDAM][MAASTRICHT]=0;
	map[AMSTERDAM][MEPPEL]=0;
	map[AMSTERDAM][NIJMEGEN]=0;
	map[AMSTERDAM][UTRECHT]=26;
	map[AMSTERDAM][DEN_HELDER]=77;
	
	map[DEN_HAAG][AMSTERDAM]=46;
	map[DEN_HAAG][DEN_HAAG]=0;
	map[DEN_HAAG][EINDHOVEN]=89;
	map[DEN_HAAG][ENSCHEDE]=0;
	map[DEN_HAAG][GRONINGEN]=0;
	map[DEN_HAAG][ZWOLLE]=0;
	map[DEN_HAAG][LEEUWARDEN]=0;
	map[DEN_HAAG][MAASTRICHT]=0;
	map[DEN_HAAG][MEPPEL]=0;
	map[DEN_HAAG][NIJMEGEN]=0;
	map[DEN_HAAG][UTRECHT]=0;
	map[DEN_HAAG][DEN_HELDER]=0;
	
	map[EINDHOVEN][AMSTERDAM]=0;
	map[EINDHOVEN][DEN_HAAG]=89;
	map[EINDHOVEN][EINDHOVEN]=0;
	map[EINDHOVEN][ENSCHEDE]=0;
	map[EINDHOVEN][GRONINGEN]=0;
	map[EINDHOVEN][ZWOLLE]=0;
	map[EINDHOVEN][LEEUWARDEN]=0;
	map[EINDHOVEN][MAASTRICHT]=63;
	map[EINDHOVEN][MEPPEL]=0;
	map[EINDHOVEN][NIJMEGEN]=55;
	map[EINDHOVEN][UTRECHT]=47;
	map[EINDHOVEN][DEN_HELDER]=0;
	
	map[ENSCHEDE][AMSTERDAM]=0;
	map[ENSCHEDE][DEN_HAAG]=0;
	map[ENSCHEDE][EINDHOVEN]=0;
	map[ENSCHEDE][ENSCHEDE]=0;
	map[ENSCHEDE][GRONINGEN]=0;
	map[ENSCHEDE][ZWOLLE]=50;
	map[ENSCHEDE][LEEUWARDEN]=0;
	map[ENSCHEDE][MAASTRICHT]=0;
	map[ENSCHEDE][MEPPEL]=0;
	map[ENSCHEDE][NIJMEGEN]=0;
	map[ENSCHEDE][UTRECHT]=0;
	map[ENSCHEDE][DEN_HELDER]=0;
	
	map[GRONINGEN][AMSTERDAM]=0 ;
	map[GRONINGEN][DEN_HAAG]=0;
	map[GRONINGEN][EINDHOVEN]=0;
	map[GRONINGEN][ENSCHEDE]=0;
	map[GRONINGEN][GRONINGEN]=0;
	map[GRONINGEN][ZWOLLE]=0;
	map[GRONINGEN][LEEUWARDEN]=34;
	map[GRONINGEN][MAASTRICHT]=0;
	map[GRONINGEN][MEPPEL]=49;
	map[GRONINGEN][NIJMEGEN]=0;
	map[GRONINGEN][UTRECHT]=0;
	map[GRONINGEN][DEN_HELDER]=0;
	
	map[ZWOLLE][AMSTERDAM]=0;
	map[ZWOLLE][DEN_HAAG]=0;
	map[ZWOLLE][EINDHOVEN]=0;
	map[ZWOLLE][ENSCHEDE]=50;
	map[ZWOLLE][GRONINGEN]=0;
	map[ZWOLLE][ZWOLLE]=0;
	map[ZWOLLE][LEEUWARDEN]=0;
	map[ZWOLLE][MAASTRICHT]=0;
	map[ZWOLLE][MEPPEL]=15;
	map[ZWOLLE][NIJMEGEN]=77;
	map[ZWOLLE][UTRECHT]=51;
	map[ZWOLLE][DEN_HELDER]=0;
	
	map[LEEUWARDEN][AMSTERDAM]=0;
	map[LEEUWARDEN][DEN_HAAG]=0;
	map[LEEUWARDEN][EINDHOVEN]=0;
	map[LEEUWARDEN][ENSCHEDE]=0;
	map[LEEUWARDEN][GRONINGEN]=34;
	map[LEEUWARDEN][ZWOLLE]=0;
	map[LEEUWARDEN][LEEUWARDEN]=0;
	map[LEEUWARDEN][MAASTRICHT]=0;
	map[LEEUWARDEN][MEPPEL]=40;
	map[LEEUWARDEN][NIJMEGEN]=0;
	map[LEEUWARDEN][UTRECHT]=0;
	map[LEEUWARDEN][DEN_HELDER]=0;
	
	map[MAASTRICHT][AMSTERDAM]=0 ;
	map[MAASTRICHT][DEN_HAAG]=0;
	map[MAASTRICHT][EINDHOVEN]=63;
	map[MAASTRICHT][ENSCHEDE]=0;
	map[MAASTRICHT][GRONINGEN]=0;
	map[MAASTRICHT][ZWOLLE]=0;
	map[MAASTRICHT][LEEUWARDEN]=0;
	map[MAASTRICHT][MAASTRICHT]=0;
	map[MAASTRICHT][MEPPEL]=0;
	map[MAASTRICHT][NIJMEGEN]=111;
	map[MAASTRICHT][UTRECHT]=0;
	map[MAASTRICHT][DEN_HELDER]=0;
	
	map[MEPPEL][AMSTERDAM]=0 ;
	map[MEPPEL][DEN_HAAG]=0;
	map[MEPPEL][EINDHOVEN]=0;
	map[MEPPEL][ENSCHEDE]=0;
	map[MEPPEL][GRONINGEN]=49;
	map[MEPPEL][ZWOLLE]=15;
	map[MEPPEL][LEEUWARDEN]=40;
	map[MEPPEL][MAASTRICHT]=0;
	map[MEPPEL][MEPPEL]=0;
	map[MEPPEL][NIJMEGEN]=0;
	map[MEPPEL][UTRECHT]=0;
	map[MEPPEL][DEN_HELDER]=0;
	
	map[NIJMEGEN][AMSTERDAM]=0;
	map[NIJMEGEN][DEN_HAAG]=0;
	map[NIJMEGEN][EINDHOVEN]=55;
	map[NIJMEGEN][ENSCHEDE]=0;
	map[NIJMEGEN][GRONINGEN]=0;
	map[NIJMEGEN][ZWOLLE]=77;
	map[NIJMEGEN][LEEUWARDEN]=0;
	map[NIJMEGEN][MAASTRICHT]=111;
	map[NIJMEGEN][NIJMEGEN]=0;
	map[NIJMEGEN][MEPPEL]=0;
	map[NIJMEGEN][UTRECHT]=0;
	map[NIJMEGEN][DEN_HELDER]=0;
	
	map[UTRECHT][AMSTERDAM]=26 ;
	map[UTRECHT][DEN_HAAG]=0;
	map[UTRECHT][EINDHOVEN]=47;
	map[UTRECHT][ENSCHEDE]=0;
	map[UTRECHT][GRONINGEN]=0;
	map[UTRECHT][ZWOLLE]=51;
	map[UTRECHT][LEEUWARDEN]=0;
	map[UTRECHT][MAASTRICHT]=0;
	map[UTRECHT][NIJMEGEN]=0;
	map[UTRECHT][MEPPEL]=0;
	map[UTRECHT][UTRECHT]=0;
	map[UTRECHT][DEN_HELDER]=0;
	
	map[DEN_HELDER][AMSTERDAM]=77;
	map[DEN_HELDER][DEN_HAAG]=0;
	map[DEN_HELDER][EINDHOVEN]=0;
	map[DEN_HELDER][ENSCHEDE]=0;
	map[DEN_HELDER][GRONINGEN]=0;
	map[DEN_HELDER][ZWOLLE]=0;
	map[DEN_HELDER][LEEUWARDEN]=0;
	map[DEN_HELDER][MAASTRICHT]=0;
	map[DEN_HELDER][NIJMEGEN]=0;
	map[DEN_HELDER][MEPPEL]=0;
	map[DEN_HELDER][UTRECHT]=0;
	map[DEN_HELDER][DEN_HELDER]=0;
	
	/*END OF MAP DECLERATION*/
		
	int disruptions;
	char city[11];
	int cancel, cancel2;		//tracks which connections to cancel
	int count=0;
	
	scanf("%d", &disruptions);
	char blank=getchar();	//captures the unneeded \n
	if(blank!='\n'){
		return 1;
	}
	/*REGISTERS DISRUPTIONS*/
	for(int i=0; i<disruptions; i++){
		
		memset(city, 0, 11);	//clear city name array
		
		int i=0;
		char c=getchar();
		while(c!='\n'){
			city[i]=c;
			c=getchar();
			i++;
		}
		
		cancel=identify(city);
		memset(city, 0, 11);
		
		i=0;
		c=getchar();
		while(c!='\n'){
			city[i]=c;
			c=getchar();
			i++;
		}
		
		cancel2=identify(city);
		memset(city, 0, 11);
		map[cancel][cancel2]=0;
		map[cancel2][cancel]=0;
		count++;
	}
	
	int start;
	int end;
	
	/*REGISTER BEGINING STOP AND END STATION*/
	for(char c=getchar();;c=getchar()){
		
		if(c=='!'){
			break;
		}
		
		int i=0;
		while(c!='\n'){
			city[i]=c;
			c=getchar();
			i++;
		}

		start=identify(city);
		//printf("%s %d\n", city, identify(city));
		memset(city, 0, 11);
		
		i=0;
		c=getchar();
		while(c!='\n'){
			city[i]=c;
			c=getchar();
			i++;
		}		
		end=identify(city);
		pathFinder(map, start, end);
		memset(city, 0, 11);
	}
	return 0;
}

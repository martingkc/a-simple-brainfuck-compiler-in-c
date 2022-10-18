#include <stdio.h>
#include<string.h>
#define MAX 2000


int findparl(int tmp, char* string){
	int countpar; 
	int i; 
	i = tmp; 
	countpar = -1; 


	while(countpar != 0){
		i++;
		if( string[i] == '['){
			countpar = countpar -1; 
			

		}
		if(string[i] == ']'){
			countpar = countpar +1 ; 
			

		}
		
	}
	return i; 
	
}
int findparr(int tmp, char* string){
	int countpar; 
	int i; 
	i = tmp; 
	countpar = -1; 


	while(countpar != 0){
		i--;
		if( string[i] == '['){
			countpar = countpar +1; 
			

		}
		if(string[i] == ']'){
			countpar = countpar -1 ; 
			

		}
		
	}
	return i; 
	
}
int* compile(char* string, int length){
	static int transl[MAX] = {0};
	int i,j,tmp; 

	for(i = 0, j= 0; i<length; i++){

		switch(string[i]){
			case'+':
				transl[j]=transl[j]+1; 
				break; 
			case'-': 
				transl[j]=transl[j]-1; 
				break; 
			case'<':
				j--; 
				break;
			case'>':
				j++; 
				break;
			case '.': 
				printf("%c", transl[j]);
				break; 
			case',': 
				scanf("%c", transl[j]); 
				break;
			case'[': 

				if(transl[j] == 0){
					tmp = i; 
					i = findparl(tmp, string); 
					
				}
				break;

			case']': 
				if(transl[j] != 0){
					tmp = i; 
					i = findparr(tmp, string);
					
				}
				break;


		}
	}
	return transl; 


}


 int main(int argc, char  *argv[])
{
	FILE *f;
	f = fopen(argv[1], "r"); 
	char str[3000] = {0}; 
	char tmp[1024]; 
	int len;
	int *trans; 

	
	while(fscanf(f, "%s", tmp)!=-1){
		strcat(str,tmp);
		
	}

	len = strlen(str); 
	trans= compile(str, len);
	 
	for(int i = 0; i<MAX; i++){
		//printf("%d", *(trans + i)); 
	}
	
	fclose(f);
	return 0;
}

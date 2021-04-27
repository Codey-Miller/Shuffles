#include <stdio.h>
#include <string.h>
#include <conio.h>
typedef enum{false,true} bool;
int cards[52];
void inShuffle(int top[26], int bottom[26]){
	int count=0;
	int place=0;
	while(count<26){
		cards[place] = bottom[count];
		place++;
		cards[place] = top[count];
		place++;
		count++;
	}
}
void outShuffle(int top[26], int bottom[26]){
	int count=0;
	int place=0;
	while(count<26){
		cards[place] = top[count];
		place++;
		cards[place] = bottom[count];
		place++;
		count++;
	}
}
int shuffle(char type[]){
	int t = 0;
	while(t<strlen(type)){
		int top[26];
		int bottom[26];
		int c = 0;
		while(c<26){
			top[c]=cards[c];
			c++;
		}
		while(c<52){
			bottom[c-26]=cards[c];
			c++;
		}
		if(type[t]=='o'){
			outShuffle(top,bottom);
		} else {
			inShuffle(top,bottom);
		}
		t++;
	}
}
bool check(){
	int count = 0;
	while(count<52){
		if(count!=cards[count]){
			return false;
		}
		count++;
	}
	return true;
}
int main(int argc, char *argv[]){
	system("cls");
	int i = 0;
	while(i<52){
		cards[i] = i;
		i++;
	}
	int count = 0;
	do {
		shuffle(argv[1]);
		count+=strlen(argv[1]);
	} while(!check());
	printf("%s took %d times",argv[1],count);
	getchar();
}
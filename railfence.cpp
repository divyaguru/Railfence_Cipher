#include<iostream>
#include<string>
using namespace std;

class Railfence{
public:
	int up;
	int down;
	int j;
	
	Railfence(){
		up=0;
		down=1;
		j=0;
	}
	
	string cipher(string s, int numRows) {
	    int len = s.length();
    
	    if(len<=numRows || numRows==1){
	        return s;
	    }
    
	    char arr[numRows][len];
	    string output;
    
	    //....................................................
	    //......INITIALIZING ALL CHARACTERS TO SPECIAL CHARACTER......
	    //....................................................
    
    
	    for(int i=0; i<numRows; i++){
	        for(int j=0; j<len; j++){
	            arr[i][j] = ' ';
	        }
	    }
    
    
	    //....................................................
	    //......ARRANGING THE LETTERS IN A ZIGZAG MANNER......
	    //....................................................
    

	    for(int i=0; i<len; i++){
	        if(down==1 && j!=numRows){
	            arr[j][i] = s[i];
	            if(j+1==numRows){
	                j--;
	                down=0; up=1;
	            }
				else j++;
	        }
        
	        else if(up==1 && j!=-1){
	            arr[j][i] = s[i];
	            if(j-1==-1){
	                j++;
	                down=1; up=0;
	            }
				else j--;
	        }
	    }
	
    
	    //.........................................................
	    //......READING THE ZIGZAG LETTERS IN A STRAIGHT LINE......
	    //.........................................................
    
	    for(int row=0; row<numRows; row++){
	        for(int col=0; col<len; col++){
	            char t;
	            t = arr[row][col];
	            if(t!=' '){
	                output += t;
	            }
	        }
	    }
	    return output;
	}
};
	int main(){
	    string s;
		Railfence rail;
	    int rows;
		cout<<"Enter a string and the number of rows:\n--> ";
	    cin>>s;
		cout<<"--> ";
		cin>>rows;
    
	    string result = rail.cipher(s, rows);
	    cout<<"\nCipherText : "<<result<<"\n";
    
	    return 0;
	}

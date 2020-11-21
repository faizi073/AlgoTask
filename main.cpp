#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 

using namespace std;
double s,t;
double buildinga,buildingb;
int m,n;
double *redballdistance, *blueballdistance;

void readValueOfST(string value){
	stringstream ss;	 
	ss << value; 
	ss >> s;
	ss >> t; 
}

void  readValueOfAB(string value){
	stringstream ss;	 
	ss << value; 
	ss >> buildinga;
	ss >> buildingb;
}

void  readValueOfMN(string value){
	stringstream ss;	 
	ss << value; 
	ss >> m;
	ss >> n;
}



void readValueOfRedBall(string value)
{
	stringstream ss;     
    ss << value; 
    redballdistance= new double[m];
    string temp; 
    double found; 
    int count=0;
    while (!ss.eof()) { 
  
        ss >> temp; 
  
        if (stringstream(temp) >> found){
        	redballdistance[count]=found;
        }
  		count++;
        temp = ""; 
    }
}

void readValueOfBlueBall(string value)
{
	stringstream ss;     
    ss << value; 
    blueballdistance= new (nothrow) double[n];
    string temp; 
    double found; 
    int count=0;
    while (!ss.eof()) { 
  
        ss >> temp; 
  
        if (stringstream(temp) >> found){
        	blueballdistance[count]=found;
        }
        
        count++;
  
        temp = ""; 
    }
}

void saveresultinfile(int a, int b)
{
	ofstream fout;
	fout.open("Result.TXT");
	fout<<a<<endl<<b;
	fout.close();
}
void result()
{
	cout<<"After Adding Red and A [building A distance]\n";
	int NewRedBall[m];
	for(int i=0;i<m;i++)
	{
		NewRedBall[i]=redballdistance[i]+buildinga;
		cout<<redballdistance[i]<<"\t = "<<NewRedBall[i]<<"\n";
	}
	
		cout<<"After Adding Blue and B [building B distance]\n";

	
	int NewBlueBall[n];
	for(int i=0;i<n;i++)
	{
		NewBlueBall[i]=blueballdistance[i]+buildingb;
		cout<<blueballdistance[i]<<"\t ="<<NewBlueBall[i]<<"\n";

	}
	
	int redballfall=0;
	int blueballfall=0;
	
	for(int i=0;i<m;i++)
	{
		if(NewRedBall[i]>=s)
			redballfall++;
	}
	
	for(int i=0;i<n;i++)
	{
		if(NewBlueBall[i]<=t)
			blueballfall++;
	}
	
	cout<<"Number of Red Balls = s"<<redballfall<<"\n"<<"Number of Blue Balls = "<<blueballfall;
	
	saveresultinfile(redballfall,blueballfall);
	
}


int main(int argc, char** argv) {
   fstream newfile;   
   newfile.open("task1.txt",ios::in); 
   string tp;

	
   if (newfile.is_open()){  
   
   		getline(newfile,tp);
   		readValueOfST(tp);
   		
   		getline(newfile,tp);
   		readValueOfAB(tp);
   		
   		getline(newfile,tp);
   		readValueOfMN(tp);
   		
   		getline(newfile,tp);
   		readValueOfRedBall(tp);
   		
   		getline(newfile,tp);
   		readValueOfBlueBall(tp);
    
      newfile.close();
   }
   
   result();
}





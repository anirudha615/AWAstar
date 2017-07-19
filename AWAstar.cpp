#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;

string a;
ofstream myfile;
float b = 0.0f;
long long SIZE;
long long w=0;
long long e=0;
long long u=0;
long long T;
float dx[]={1,1.414f,0,-1.414f,-1,-1.414f,0,1.414f};float dy[]={0,1.414f,1,1.414f,0,-1.414f,-1,-1.414f};
long long sx,sy,fx,fy,g_cost_cell[5000][5000],f_cost_cell_old[5000][5000],f_cost_cell_new[5000][5000],f_cost_incumbent[5000][5000];
long long distance(long long x,long long y,long long p,long long q);
long long heuristic(long long x,long long y);
static long long maze[5000][5000];
static long long maze1[5000][5000];
long long best_Sol = 9999999999;

struct Vector
{
    std::pair<long long,long long> er;
    Vector(long long e_ = 0,long long r_ = 0) : er(std::make_pair(e_, r_)) {}
    bool operator<(const Vector& rhs) const
    { return er < rhs.er; }
    
};

struct op
{
	long long x,y,cost,h,total_cost;
	op(long long _x,long long _y,long long _cost)
	{
	    x=_x;y=_y;cost=_cost;
	    h=heuristic(x,y);
	    total_cost=cost+h;
	}
	bool operator<(const op &b)const
       {
	   return total_cost>b.total_cost;    
       }
};

long long heuristic(long long x,long long y)
{
	return (1+b) * (abs(x-fx)+abs(y-fy));
}

long long distance(long long x,long long y, long long m, long long n)
{
	return abs(x-m)+abs(y-n);
}

long long astar(long long x,long long y)
{
	clock_t tStart = clock();
	long long i,j,m,n;
	set<Vector>C;
	set<Vector>R;
	set<Vector>O;
	priority_queue<op>Q;
	O.insert(Vector(x,y));
	Q.push(op(x,y,0));
   	while((!Q.empty()) && (!O.empty()))
	{
		
        	op P=Q.top();
		Q.pop();
		x=P.x;y=P.y;
		const bool is_in = O.find(Vector(x,y)) != O.end();
		const bool is_inty = R.find(Vector(x,y)) != R.end();
		if (is_in)
		{
		if (is_inty) w++;
		
		
		//cout<<"current node is ("<< x<<","<<y<<")"<<endl;
		//cout<<"The F-cost of current node is ("<< x<<","<<y<<") is :"<<P.cost+P.h<<endl;
		//cout<<"the node is ("<<x<<","<<y<<")"<<"is being shifted from open list to closed list"<<endl;
		g_cost_cell[x][y]=P.cost;
		f_cost_cell_old[x][y]=P.cost+P.h;
		maze1[x][y] = f_cost_cell_old[x][y];
		e++;
		if (f_cost_cell_old[x][y] >= best_Sol) {
			//cout<<"Can't Expand you"<<endl<<endl;
			u++;
			continue;
		}
		else { O.erase(Vector(x,y)); C.insert(Vector(x,y));
		//cout<<"Now we are expanding the current node("<< x<<" "<<y<<")"<<endl;  
		for(i=0;i<8;i++)
	        {
	            m=x+dx[i];
	            n=y+dy[i];
		    if (maze[m][n] ==1) continue;
	            if((m>=0 && m<SIZE && n>=0 && n<SIZE) && ((g_cost_cell[x][y]+distance(m,n,x,y)+heuristic(m,n))< best_Sol))
		    {	
				const bool is_in_C = C.find(Vector(m,n)) != C.end();	
				const bool is_in_O = O.find(Vector(m,n)) != O.end();
				if (heuristic(m,n) == 0) 
				{	
					cout<<endl<<"Best Solution updated from : "<<best_Sol;
					best_Sol = g_cost_cell[x][y]+distance(x,y,m,n);
					Q.push(op(m,n,g_cost_cell[x][y]+distance(x,y,m,n)));
					O.insert(Vector(m,n));
					cout<<" to :"<<best_Sol<<endl;
					
  				}
			 	else if((is_in_C) || (is_in_O))
				{  
					g_cost_cell[m][n] = g_cost_cell[x][y]+distance(m,n,x,y);
					f_cost_cell_new[m][n] = g_cost_cell[m][n]+heuristic(m,n);
					if ((f_cost_cell_new[m][n] < f_cost_cell_old[m][n]))
					{
						C.erase(Vector(m,n));
						O.insert(Vector(m,n));
						R.insert(Vector(m,n));
						//cout<<"the node ("<<m<<","<<n<<") is shifted from closed list to openlist"<<endl;
						//cout<<"The F-cost of the node ("<<m<<","<<n<<") is :"
						//<<g_cost_cell[m][n]+((1+b) *heuristic(m,n))<<endl;
						Q.push(op(m,n,g_cost_cell[m][n]));
					}
					else continue;
  				}
				else if ((!is_in_C) || (!is_in_O)) 
				{
					g_cost_cell[m][n]=g_cost_cell[x][y]+distance(m,n,x,y);
					O.insert(Vector(m,n));
				//cout<<"the node ("<<m<<","<<n<<") is shifted to openlist"<<endl;
				//cout<<"The F-cost of the node ("<<m<<","<<n<<")  is :"<<g_cost_cell[m][n]+((1+b)*heuristic(m,n))<<endl;
                			Q.push(op(m,n,g_cost_cell[m][n]));
				
				}
		      }
	       }
}
}
b/=10.5;
}
}
                                     
void file_read () 
{
string line; 
  	//std::ifstream myfile (a.c_str());
	std::ifstream myfile ("matrix.txt");
	if (myfile)
  	{
    	while ( getline (myfile,line) )
    	{ 
	if (line == "Problem:") break;
    	}
	getline(myfile,line);
	SIZE =atoi(line.c_str());
	cout<<"SIZE of the matrix is :"<<SIZE<<endl;
	getline(myfile,line);
	for (long long j=0;j<SIZE;j++){
            for(long long k=0;k<SIZE;k++){
		maze[j][k] = atoi(line.c_str());
		getline(myfile,line);
            }

        }
	myfile.close();
	}
	else cout<<"Sorry!"<<endl;
}

void matrix_print()
{
	for (long long j=0;j<SIZE;j++){
            cout<<endl;
            for(long long k=0;k<SIZE;k++){
                cout<<setw(3)<<maze[j][k];
            }

        }
cout<<endl;
}

void matrix_search()
{
for (long long j=0;j<SIZE;j++){
            cout<<endl;
            for(long long k=0;k<SIZE;k++){
                cout<<setw(3)<<maze1[j][k];
            }
        }
cout<<endl<<endl;
}

int main()
{
	clock_t tStart = clock();
	cout<<"Matrix Description :"<<endl;
	/*cout<<"Enter the name of your file: "<<endl;
	std::getline (std::cin,a);*/
	cout<<"Enter the inflation factor: "<<endl;
	cin>>b;
	file_read();
	if (SIZE == 10) matrix_print();
	cout<<endl<<"Start :";
	cin >>sx>>sy;
	if (maze[sx][sy] == 1)
	{
		cout<<"The start is an obstacle"<<endl;
		exit(0);
	} 
	cout<<"Goal :";
	cin>>fx>>fy;
	if (maze[fx][fy] == 1)
	{
		cout<<"The goal is an obstacle"<<endl;
		exit(0);
	} 
	astar(sx,sy);
	if (SIZE == 10) matrix_search();
	if (f_cost_cell_old[fx][fy] == 0) cout<<"No path has been found"<<endl;
	else cout<<"The goal has been found"<<endl<<"the fcost is "<< f_cost_cell_old[fx][fy]<<endl;
	cout<<"The number of nodes expanded are :"<<e-w<<endl;
	cout<<"The number of nodes re-expanded are :"<<w<<endl;
	cout<<"The number of nodes which want to expand but F-cost is > best_sol are :"<<u<<endl;
	printf("Total Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cout<<endl;
	cout<<"Best Solution is :"<<best_Sol<<endl<<endl;
	return 0;
}


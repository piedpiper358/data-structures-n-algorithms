#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

typedef std::vector<int> EdgeVec;
typedef std::vector<EdgeVec> Graph;

inline int changecolor(int colour){
    if(colour==RED) return BLUE;
    if(colour==BLUE) return RED;   
};

int DFS(const Graph &g, int* colours, int s, int colour );

int main()
{
    int N;
    int K;
    cin >> N;
    
    Graph g(N);
    int colours[N];
    for(int i = 0; i < N; i++)
    {
        colours[i]=WHITE;

    }
    memset(colours, WHITE, N*sizeof(int))
    for(int i = 0; i < N; i++)
    {
        while(1)
        {
            cin >> K;
            if(K==0)break;
            g[i].push_back(K-1);
            g[K-1].push_back(i);


        }
    }
    int res=0;
    for(int j=0; j<N; j++){
        if(colours[j]==WHITE){
        res+=DFS(g, colours, j, RED);
    }
     }   
    if(res==0){
        for(int i = 0; i < N; i++)
        {
        cout << colours[i]-1; 

        }

    }
    else{
        cout << -1;
    }


    cout << "\n";

}



int DFS(const Graph &g, int* colours, int s, int colour )
{
    colours[s]=colour;
    
    for (int i = 0; i < g[s].size(); ++i) {

        const int v = g[s][i];
        if(colours[v]==colour || colours[v]==WHITE && DFS(g, colours, v, changecolor(colour))){
            return 1;
        }        
    }
    return 0; 
}

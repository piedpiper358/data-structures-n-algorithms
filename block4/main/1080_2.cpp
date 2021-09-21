#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include <queue>

using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

/*enum{
    RED,
    BLUE
}colour*/

typedef std::vector<int> EdgeVec;

typedef std::vector<EdgeVec> Graph;

inline int changecolour(int colour) {
  if (colour == RED)
    return BLUE;
  if (colour == BLUE)
    return RED;
};

int DFS(/*const Graph*/ /*EdgeVec*/ int **g, /*vector<int>*/ int *colours,
        int s, int colour, int N);
int BFS(const Graph &g, vector<int> &colours, int s);

int main() {
  int N;
  int K;
  cin >> N;
  Graph g(N);
  // EdgeVec g(N);
  //std::vector<EdgeVec(N)> g(N);
  //int g[N][N];
    vector<int> colours(N);
  //int colours[N];
  for (int i = 0; i < N; i++) {
    colours[i] = WHITE;
  }
  /*for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      g[i][j] = WHITE;
    }
  }*/
  for (int i = 0; i < N; i++) {
    EdgeVec ev;
    // colour[i]=curColor;

    while (1) {
      cin >> K;
      if (K == 0)
        break;
      // cout << K;

      //ev.push_back(K-1);

      g[i].push_back(K-1);
      g[K-1].push_back(i);
      // g[K-1].push_back(i);
      //g[i][K - 1] = 1;

      //g[K - 1][i] = 1;
    }
    //g.push_back(ev);
     //g[i]=ev;
  }
for (int i = 0; i < g.size(); i++) {
    for (int j = 0; j < g[i].size(); j++) {
    cout << g[i][j];
  }
  cout << "\n";
    }
  int res = 0;
  for (int j = 0; j < 1; j++) {
    if (colours[j] == WHITE) {
      //res += DFS((int **)g, colours, j, RED, N);

      res += BFS(g, colours, j);
    }
  }
  if (res == 0) {
    for (int i = 0; i < N; i++) {
      cout << colours[i] - 1; //<< " ";
    }

  } else {
    cout << -1;
  }

  cout << "\n";
}






//typedef std::vector<int> EdgeVec;

//typedef std::vector<EdgeVec> Graph;

// Assumes nodes are numbered starting from zero

int BFS(const Graph &g, vector<int> &colours, int s)

{
    int colour=RED;

    //std::vector<int> visited(g.size());
    //visited[s] = 1;
    colours[s]=colour;

    queue<int> queue;
    //queue.enqueue(s);
    queue.push(s);

    while (!queue.empty()) {

        int u = queue.front();
        queue.pop();
        cout << "u" << u;

        for (int i = 0; i < g[u].size(); ++i) {

          int v = g[u][i];

          cout << "v" << v <<colours[v];
          if(colours[v] == colour){
            return 1;
          }

          if (colours[v] == WHITE || colours[v] == changecolour(colour)) {
            //cout<<;

            colours[v]=changecolour(colour);

            queue.push(v);
          }
        }

        colour=changecolour(colour);
    }
    return 0;
}



int DFS(/*const Graph*/ /*EdgeVec*/ int **g, /*vector<int>*/ int *colours,
        int s, int colour, int N) {
  colours[s] = colour;
  cout << s + 1 << colour << " ";

  for (int i = 0; i < N; i++) {
    if (g[s][i] == 1 || g[s][i] == 1) {

      const int v = i;
      cout << "v" << v;
      if (colours[v] == colour ||
          colours[v] == WHITE && DFS(g, colours, v, changecolour(colour), N)) {
        return 1;
      }
    }
  }
  return 0;
}

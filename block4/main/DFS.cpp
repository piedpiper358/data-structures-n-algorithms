#define WHITE 0
#define GRAY 1
#define BLACK 2

class Node {

public:
  Node() : color(WHITE), predecessor(-1) { /* */
  }

  int color;

  int predecessor;

  int in, out;
};

typedef std::vector<int> EdgeVec;

typedef std::vector<EdgeVec> Graph;

typedef std::vector<Node> VisitedMap;

void DFS(const Graph &g, VisitedMap &vmap)

{

  int t = 0;

  for (int i = 0; i < g.size(); ++i)

    if (vmap[i].color == WHITE)
      DFS_visit(g, i, vmap, t);
}

void DFS_visit(const Graph &g, int s, VisitedMap &vmap, int &t)

{

  vmap[s].color = GRAY;

  cout << “in(” << s << “)” << endl;

  vmap[s].in = t++;

  for (int i = 0; i < g[s].size(); ++i) {

    const int v = g[s][i];

    if (vmap[v].color == WHITE) {

      vmap[v].predecessor = s;

      DFS_visit(g, v, vmap, t);
    }
  }

  cout << “out(” << s << “)” << endl;

  vmap[s].out = t++;

  vmap[s].color = BLACK;
}
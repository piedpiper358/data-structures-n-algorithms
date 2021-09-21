#include <stdio.h>
#include <vector>
#include <algorithm>

struct node
{
    node* parent;
    int rank;
    int n;
    node() : parent(this), rank(0) { }
};

struct edge
{
    node* a, *b;
    int weight;
    edge(node* a, node* b, int weight) : a(a), b(b), weight(weight) {}
};

void link(node* a, node* b); 
node* find(node* s);
void join(node* a, node* b);

std::vector<node> nodes;
std::vector<edge> edges;
std::vector<edge*> answer;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    nodes.reserve(N+1);

    for(int i = 0; i < N+1; i++)
    {

        nodes.push_back(node());

        nodes.back().parent = &nodes.back();
        nodes.back().n = i;

    }

    edges.reserve(M);
    answer.reserve(M); 
    for(int i = 0; i < M; i++)
    {

        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        edges.emplace_back(&nodes[x], &nodes[y], w);
    }
    std::sort(edges.begin(), edges.end(), [] (edge& a, edge& b) { return a.weight < b.weight; });
    int max = 0;
    for(edge& e : edges)
    {

        if(find(e.a) != find(e.b))
        {

            join(e.a, e.b);
            max = std::max(max, e.weight);
            answer.push_back(&e);
        }
    }
    printf("%d\n", max);
    printf("%d\n", answer.size());

    for(auto e : answer){

        printf("%d %d\n", e->a->n, e->b->n);
    }
    return 0;
}
node* find(node* s) 
{
    if(s != s->parent){

        s->parent = find(s->parent);
    }
    return s->parent;
}
void join(node* a, node* b) 
{
    link(find(a), find(b));
}

void link(node* a, node* b) 
{
    if(a->rank > b->rank){
        b->parent = a;
    }
    else
    {
        a->parent = b;
        if(a->rank == b->rank){

            b->rank++;
        }
    }
}




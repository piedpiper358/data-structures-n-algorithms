#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int, int> Pair;

bool comp1(Pair a, Pair b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
}

bool comp2(Pair a, Pair b){
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}

Pair cell[180000];

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    int x, y;
    
    for(int i = 0; i<K; ++i){
        cin >> x >> y;
        cell[i] = make_pair(x,y);
    }
    
    for(int i = 1; i<=M; ++i){
        cell[K++] = make_pair(0,i);
        cell[K++] = make_pair(N+1,i);
    }
    
    for(int i = 1; i<=N; ++i){
        cell[K++] = make_pair(i,0);
        cell[K++] = make_pair(i,M+1);
    }
    
    int ans = 0;
    set<Pair> S;
    
    sort(cell,cell+K,comp1);
    
    for(int i = 0; i+1<K; ++i){
        int diff = cell[i+1].second-cell[i].second;
        
        if(cell[i].first==cell[i+1].first && diff>=2){
            if(diff==2) S.insert(make_pair(cell[i].first,cell[i].second+1));
            else ++ans;
        }
    }
    
    sort(cell,cell+K,comp2);
    
    for(int i = 0;i+1<K;++i){
        int diff = cell[i+1].first-cell[i].first;

        if(cell[i].second==cell[i+1].second && diff>=2){
            if(diff!=2 || S.find(make_pair(cell[i].first+1,cell[i].second))!=S.end()){
                    ++ans;
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
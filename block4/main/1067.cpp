#include <iostream>
#include <map>
#include <sstream>
#include <string>

//#include <malloc.h>
#include <vector>

using namespace std;

struct dir
{
    std::map<std::string, dir*> subs;
};
std::vector<dir> dirs(1);
//dir* root = &dirs[0];
int p = 1;

dir* addDir(dir* curdir, std::string str)
{
    auto& d = curdir->subs[str];
    if(!d)
    {
    	//d = (struct dir*) malloc(sizeof(dir));
    	//d = &dirs[p++];
    	dir *newdir = new dir;
    	//d = newdir;
    	//
    	dirs.resize(dirs.size()+1);
    	dirs.push_back(*newdir);
    	d=&dirs.back();
    }
        
    return d;
}

void print(dir* dir, int depth = 0)
{
    for(auto s : dir->subs)
    {
        for(int i = 0; i < depth; i++)
            cout << " ";
        cout << s.first << "\n";
        print(s.second, depth+1);
    }
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string str, dirstr;
        cin >> str;
        stringstream ss(str);
        //dir* dir = &dirs[0];
        dir* dir = &dirs[0];
        while (getline(ss, dirstr, '\\'))
        {
        	//printf("%s", dirstr);
        	//cout << dirstr << "\n";
            dir = addDir(dir, dirstr);
        }
    }
    print(&dirs[0]);
    //print(&root);
}
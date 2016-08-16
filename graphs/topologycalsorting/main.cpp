#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define vec vector

struct node {
    lli indeg = 0;
    vec<lli> adjlist;
};

class graph{
    lli noOfNodes;
    node * nodearr;

public:
    graph(lli n){
        noOfNodes = n;
        nodearr = new node[noOfNodes+1];
    }

    void addEdge(lli p, lli q) {
        nodearr[q].indeg++;
        nodearr[p].adjlist.push_back(q);
    }

    void tsort() {
        list<lli> s;
        vec<lli> l;

        for (lli i = 1; i <= noOfNodes; i++) {
            if(nodearr[i].indeg == 0)
                s.push_back(i);
        }

        while(!s.empty()){
            //cout << " #size : "<< s.size() << endl;
            l.push_back(s.front());
            for(lli i = 0; i < nodearr[s.front()].adjlist.size(); i++){
                nodearr[nodearr[s.front()].adjlist[i]].indeg--;
               // cout << " ## indeg : " << nodearr[s.front()].adjlist[i] << " -> " << nodearr[nodearr[s.front()].adjlist[i]].indeg << endl;
                if(nodearr[nodearr[s.front()].adjlist[i]].indeg == 0)
                    s.push_back(nodearr[s.front()].adjlist[i]);
            }
            s.pop_front();
        }

        cout << endl << " print sorted list " << endl;

        for (int j = 0; j < l.size(); ++j) {
            cout << l[j] << " ";
        }

    }

    void printAdjList(){

        cout << " Printing list " << endl;
        for(lli i = 1; i <= noOfNodes; i++){
            cout << i;
            for(lli j = 0; j < nodearr[i].adjlist.size(); j++)
                cout << " -> " << nodearr[i].adjlist[j];

            cout << endl;
        }
    }

};


int main() {
    graph p(8);
    // adding edge;
    p.addEdge(1,2);
    p.addEdge(2,3);
    p.addEdge(2,8);
    p.addEdge(2,6);
    p.addEdge(4,2);
    p.addEdge(4,5);
    p.addEdge(5,6);
    p.addEdge(7,5);
    p.addEdge(7,8);


    // print adj list

    p.printAdjList();
    // call for sort

    p.tsort();
    return 0;
}

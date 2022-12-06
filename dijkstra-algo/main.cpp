#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2137000000  //  Infinity as big number

using namespace std;

class Graph{
    public:
        Graph(int V){                                 
            this->verticesCount = V;   // Setting number of verticies
            edges = new vector<pair<int,int>>[V];   // Creating vector of edges for each vertice
        }
        void addEdge(int v, int u, int w){  //  Adding edge from v to u with weight of w
            edges[v].push_back({u,w});
            edges[u].push_back({v,w});
        }
        void solve(int s){  //  Finding shortest path to each vertice from s using dijkstra algo

            vector<int> distance(this->verticesCount,INF);  //  Vector of distances from source to each vertice
            vector<bool> unvisited(this->verticesCount,true);   //  Information which vertice has been visited
            distance.at(s) = 0; //  Setting distance to source vertice as 0

            while(count(unvisited.begin(),unvisited.end(),true) > 0){
                int visited = min(distance,unvisited);  //  Getting unvisited vertice with shortest distance from source
                unvisited[visited] = false; //  Setting vertice as visited

                for(auto edge : edges[visited]){    //  Getting edges coming from vertice
                    int u = edge.first;
                    int d = edge.second+distance[visited];
                    if(distance[u] > d){    //  If distance to vertice u from vertice visited is shorter
                        distance[u] = d;    //  than distance set previously, setting it as a distance
                    }
                }
                
            }

            for(size_t i=0; i<distance.size(); i++){   //  Printing distance to every vertice
                cout << "Distance " << s << "->" << i << " = " << distance.at(i) << endl;
            }
        }
    private:
        vector<pair<int,int>>* edges;
        int verticesCount;

        int min(vector<int> distance,vector<bool> visited){ //  Finding index of vertice with smallest distance that
            int val = INF+1;                                  // has not been visited yet.
            int index = -1;
            for(size_t i = 0; i < distance.size(); i++){
                if(visited.at(i) && val > distance.at(i)){
                    val = distance.at(i);
                    index = i;
                }
            }
            return index;
        }
};

int main(){
    Graph g(9); // Setting example graph

    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,7,11);
    g.addEdge(1,2,8);
    g.addEdge(7,8,7);
    g.addEdge(7,6,1);
    g.addEdge(2,8,2);
    g.addEdge(8,6,6);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    g.addEdge(6,5,2);
    g.addEdge(3,4,9);
    g.addEdge(3,5,14);
    g.addEdge(5,4,10);

    g.solve(0); //  Solving for source at 0

    return 0;
}
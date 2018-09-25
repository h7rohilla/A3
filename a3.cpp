#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Graph{
  int num_vertex;
  vector<int> *vertex;
public:
    Graph(int vertices){
      num_vertex = vertices;
      vertex = new vector<int> [vertices+1];
    }

    void add_edge(int v1, int v2){
      vertex[v1].push_back(v2);
      vertex[v2].push_back(v1);
    }

    void print_graph(){
      for(int i = 1;i<=num_vertex;i++)
      {
        cout<<"list for vertex"<<i<<"  ";
        for(auto x: vertex[i]){
          cout<<x<<"  ";
        }
        cout<<endl;
      }
    }

};

int main()
{
  ifstream file("test.graph");
  int vertices, edges;
  file>>vertices>>edges;
  int vella;
  file>>vella;
  int v1,v2;
  Graph graph(vertices);
  for(int edge = 0;edge < edges; edge ++){
    file>>v1>>v2;
    graph.add_edge(v1,v2);
  }
  graph.print_graph();

  return 0;
}

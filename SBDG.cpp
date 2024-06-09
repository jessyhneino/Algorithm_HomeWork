#include<iostream>
#include<stack>
using namespace std;
int static dfscounter=1;
int static const unvisited=-1,active=0,finished=1;
class Graph{
    private:
    int V,E;
  int* vertex;
  int** edges;
  int* state;
  int* dfsnum;
  int* comp;
    stack<int> Ostack,Rstack;
    public:
      Graph(int V,int E,int* vertexarray,int** edgearray){
        this->V=V;
        this->E=E;
        vertex=new int[V];
        edges=new int*[V];
        state=new int[V];
        dfsnum=new int[V];
        comp=new int[V];
           for(int i=0;i<V;i++){
          vertex[i]=vertexarray[i];
          edges[i]=new int[V];
          state[i]=unvisited;
          dfsnum[i]=-1;
          comp[i]=-1;
        }
      int count=0;
      for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(edgearray[i][j]==1){
              count++;
          }
        }
    }
      if (count==E) {
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
              edges[i][j]=edgearray[i][j];
          }
        }
      }
      else cout<<"the number of edges you entered is not accurate! ";
    }
    void setedges(int** edgearray,int V,int E){
      this->E=E;
      this->V=V;
      int count=0;
      for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(edgearray[i][j]==1)  count++;
        }
      }
      if(count==E){
        for(int i=0;i<V;i++){
          for(int j=0;j<V;j++){
              edges[i][j]=edgearray[i][j];
          }
        }
      }
      else cout<<"the number of edges you entered is not accurate! ";
    }
    void addedge(int i,int j){
      if(edges[i][j]!=1) edges[i][j]=1;
      E++;
    }
    void deleteedge(int i,int j){
      if(edges[i][j]==1) edges[i][j]=0;
      E--;
    }
    bool exist(int j,stack<int> S){
      while(!S.empty()){
        if(j!=S.top()) S.pop();
        else {
          return 1;
          break;
        }
      }
      return 0;
    }
    void dfs(int v){
      state[v]=active;
      dfsnum[v]=dfscounter;
      dfscounter++;
      Ostack.push(v);
      Rstack.push(v);
        for(int j=0;j<V;j++){
          if(edges[v][j]==1){
            if (state[j]==unvisited) dfs(j);
            else if(exist(j,Ostack)){
              while(dfsnum[j]<dfsnum[Rstack.top()]) Rstack.pop();
            }
          }
        }
      state[v]=finished;
      if(v==Rstack.top()){
        Rstack.pop();
        int w;
        do{
          w=Ostack.top();
          Ostack.pop();
          comp[w]=v;
        }while (w!=v);
      }
    }
    void Gabow(){
      for(int i=0;i<V;i++){
        if (state[i]==unvisited) dfs(i);
      }
    }
    bool isStronglyconnected(){
      Gabow();
      int component=comp[0];
      for(int i=0;i<V;i++){
        if(comp[i]!=component){
          return false;
        }
      }
      return true;
    }
    ~Graph(){
      delete []vertex;
      delete []state;
      delete []comp;
      delete []dfsnum;
      for(int i=0;i<V;i++){
        delete[] edges[i];
      }
      delete[]edges;
    }

              //     Zein Alkhnaisee 6395 && Heba Kheder 6116

void RemoveDirectedEdges()
    {
         for(int i = 0 ; i<V ; i++ )
            for(int j = 0 ; j<V ; j++ )
             if(edges[i][j]==1)
              addedge(j,i);
        }

void dfs_jens(int i,int **edgesTE,int**edgesBE){
   edgesTE = new int*[0];
   edgesBE = new int*[0];
    dfs(i);
    for(int i = 0 ; i<E ; i++ )
       for(int j = 0 ; j<E ; j++ )
        if(edges[i][j]==1)
                if(state[j]==unvisited)
                    {
                        setedges(edgesTE,i,j);
                        setedges(edgesTE,i,j);
                }
                else if(state[j]==active)
                    {
                        setedges(edgesBE,i,j);
                        setedges(edgesBE,i,j);
                        }
                        }
void series(int **edgesTE,int **edgesBE)
    {
         for(int i = 0 ; i<E ; i++ ){
       for(int j = 0 ; j<E ; j++ ){
        if(edgesTE[i][j]==1)
            if(dfsnum[i]<dfsnum[j])
                deleteedge(i,j);
         if(edgesBE[i][j]==1)
                 if(dfsnum[i]<dfsnum[j])
                deleteedge(j,i);}
    }}
//Yosef Aloosh 6361 && Maya Jarkas 6399 && Zeina Kaso 6521

    
    Void jens (int i,int edgesTE,int edges BE)
dfs_jens(i,TE,BE)
int**ci;
for (i=0;i++;i<n)
   for (j=0;j++;j<n)
       if (BE[i][j]==1)
                 dfs(j);
setedges(ci,i,j);
for (i=0;i++;i<n)
   for (j=0;j++;j<n)
   if(edges[i][j]==1&&ci[i][j]!=1){  
        cout<<"this graph isn't two connect or two edge connect ";
    else (Ci is cycle and i !=1)
        cout<<"this graph is 2-edge connected but isn't 2-connected";
    else
      System.out.println("this graph is 2-connected")
}
//Jessy Hneno 6557 ..... Jawa Zodi 6495  ..... Mahmoud Alkhansa 5630 .... Aya Suleiman 6317 .... Hazem Kanani 5846
    };
    int main(){
      int V;
      cout<<"enter num of verteces:";
      cin>>V;
      int E;
      cout<<"enter num of Edges:";
      cin>>E;
      int* vertexarray=new int[V];
      int value1,value2;
    for(int i=0;i<V;i++){
      cout<<"enter the "<<i+1<<" vertex:";
      cin>>value1;
      vertexarray[i]=value1;
    }
      int** edgearray=new int*[V];
      for(int i=0;i<V;i++){
        edgearray[i]=new int[V];
        for(int j=0;j<V;j++){
          cout<<"Is ("<<i+1<<","<<j+1<<") an edge in G //NOTE! If YES enter 1 _ If NO enter 0// ? ";
          cin>>value2;
          if (value2==1){
            edgearray[i][j]=1;
        }
        else edgearray[i][j]=0;
      }
    }
    Graph G(V,E,vertexarray,edgearray);
    if(G.isStronglyconnected()) cout<<"G is strongly connected";
    else cout<<"unfortunately,G is not Strongly connected";
      return 0;

                //     Zein Alkhnaisee 6395 && Heba Kheder 6116

  }
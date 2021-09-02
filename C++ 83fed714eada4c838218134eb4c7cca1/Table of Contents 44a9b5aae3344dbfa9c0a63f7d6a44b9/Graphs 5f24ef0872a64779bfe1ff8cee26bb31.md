# Graphs

Created: July 23, 2021 7:46 AM

# INTRODUCTION TO GRAPHS

A graph G consist of

1. Set of vertices V (called nodes), (V = {v 1 , v 2 , v 3 , v 4 ......}) and
2. Set of edges E (i.e., E {e 1 , e 2 , e 3 ......cm}

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled.png)

Unordered graphs

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%201.png)

Ordered Graph

- edge (a, b) is incident from a to b
- If an edge that is incident from
and into the same vertex, say (d, d) of (c, c) in Fig. 9.2, is called a loop.

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%202.png)

iso-morphic graphs

Two graphs are said to be isomorphic if there is a one-to-one correspondence between their vertices and between their edges such that incidence are prevented. 

### Degree

The number of edges incident on a vertex is its degree. The degree of vertex a, is written as degree (a). If the degree of vertex a is zero, then vertex a is called isolated vertex.

### Weighted Graphs

$$G = (V, E, We , W v )$$

We - weight of the edges whose domain is E.

Wv - weight to the vertices whose domain is V.

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%203.png)

shows the distance in km between four metropolitan cities in India.
Here 

V = {N, K, M, C,}

 E = {(N, K), (N,M,), (M,K), (M,C), (K,C)} 

We = {55,47, 39, 27, 113} 

Wv = {N, K, M, C} 

> The weight at the vertices is not necessary to maintain have become the
set Wv and V are same.

**Strongly connected graphs:**  

A graph G is said to complete (or fully connected or strongly connected) if there is a path from every vertex to every other vertex.

Let a and b are two vertices in the directed graph, then it is a complete graph if there is a path from a to b as well as a path from b to a.

> A complete graph with n vertices will have $n(n-1)/2$ edges.

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%204.png)

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%205.png)

A circuit is said to be elementary if it does not visit the same vertex twice.

---

## REPRESENTATION OF GRAPHS

1. Sequential representation of a graph using adjacent matrix
2. Linked representation of a graph using linked list

### ADJACENCY MATRIX

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%206.png)

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%207.png)

The adjacency matrix A of a directed graph G = (V, E) can be represented with the following conditions
$Aij$ = 1 {if there is an edge from Vi to Vj or if the edge (i, j) is member of E.}
$Aij$ = 0 {if there is no edge from Vi to Vj }

**For Weighted Graphs:**

- To represent a weighted graph using adjacency matrix, weight of the edge (i, j) is simply stored as the entry in i th row and j th column of the adjacency matrix.
- There are some cases where zero can also be the possible weight of the edge, then we have to store some sentinel value for non-existent edge, which can be a negative value. since the weight of the edge is always a positive number.

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%208.png)

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%209.png)

The adjacency matrix A for a directed weighted graph G = (V, E, W e ) can be represented as
$Aij$ = Wij { if there is an edge from Vi to Vj then represent its weight Wij .}
$Aij$ = – 1 { if there is no edge from Vi to Vj }

**DISADVANTAGES OF ADJACENCY REPRESENTATION**

1. It takes $n^{2}$ space to represent a graph with n vertices, even for a spars graph.
2. It takes O($n^2$ ) time to solve the graph problem.

---

### ADJACENCY LIST AKA LINKED LIST REPRESENTATION

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2010.png)

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2011.png)

HOW?

`vector<linked lists>`

where indices of the vector corresponds to the vertex(u) of the graph

and each linked list at that vertex a.k.a `adj[u]` takes account of the 

ADVANCED WAY

`map<int,list<int>>`  here map[u] will give you access to the adj[u]

**CREATING A GRAPH & ADDING NODES**

```cpp
class G{
    public:
        set<int> V;
        map<int,list<int>> adj;

        //adds an edge
        void add(int v,int w){
            V.insert(v);
            V.insert(w);

            adj[v].push_back(w);
        }
        void remove(int v){
            adj.erase(v);
            V.erase(v);
            for(auto u : V){
                adj[u].remove(v);
            }
        }
        void print(){
            for(auto u: V){
                cout << u << "|->";
                for(auto e: adj[u]){
                    cout << e << "->";
                }
                cout << "/" << endl;
            }
        }
};
```

> Deleting a node is quite simple here, just iterate all vertices, look for vertex i to be deleted in each adj[vi] if found delete it.

---

## GRAPH TRAVERSALS

### BREADTH FIRST SEARCH (BFS)

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2012.png)

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2013.png)

The breadth first search systematically traverse the edges of G to explore every vertex that is reachable from S. Then we examine all the vertices  neighbour to source vertex S. Then we traverse all the neighbours of the neighbours of source vertex S and so on.

**BFS(G)**

1. Input the vertices of the graph and its edges G = (V, E)
2. Input the source vertex and assign it to the variable S.
3. Add or push the source vertex to the queue.
4. Repeat the steps 5 and 6 until the queue is empty (i.e., front > rear)
5. Pop the front element of the queue and display it as visited.
6. Push the vertices, which is neighbor to just, popped element, if it is not in the
queue and displayed (i.e., not visited).
7. Exit.

**Step 1**: Initially push A (the source vertex) to the queue.

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2014.png)

**Step 2**: Pop (or remove) the front element A from the queue (by incrementing front = front +1) and display it

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2015.png)

**Step 3:** Pop the front element B from the queue and display it. Then add the
neighbouring vertices of B to the queue, if it is not in queue.

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2016.png)

One of the neighbouring element C of B is present in the queue(checked using visited mappings, So C is not added to queue

**Step 4:** Remove the front element C and display it. Add the neighbouring vertices of C,if it is not present in queue.

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2017.png)

```cpp
class BFS: public G{
    public:
        map<int,bool> vis;

        void traverse(int source){
            queue<int> q;
            q.push(source);
            vis[source] = true;
            while(!q.empty()){
                int u = q.front();
                cout << u << " ->";
                for(auto e : adj[u]){
                    if(vis[e]==false){
                        q.push(e);
                        vis[e] = true;
                    }
                }
                q.pop();
            }
            cout << "x" << endl;

        }
};
```

### DEPTH FIRST SEARCH (DFS)

Given an input graph G = (V, E) and a source vertex S, from where the
searching starts. First we visit the starting node. Then we travel through each node along a path, which begins at S. That is we visit a neighbour vertex of S and again a neighbour of a neighbour of S, and so on.

**DFS_VISIT(vertex)**{

cout << vertex ;

for e in adj[vertex]:

if e is not visited:

DFS_VISIT(e)

}

DFS(){

for each vertex:

if each is not visited:

DFS_VISIT(each)

}

### DIFFERENCE BETWEEN BFS  VS DFS

![Untitled](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2018.png)

```cpp
#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:

    set<int> V;
    map<int,bool> vis;
    map<int,list<int>> adj;

    void addEdge(int v,int w);
    void print();
    void DFS_VISIT(int v);
    void DFS();

};

void Graph::addEdge(int v,int w){
    //? adj[v] will give us the mapped linked list
    //? now we push_back w's value in v's list.
    V.insert(v);
    V.insert(w);
    adj[v].push_back(w);
}

void Graph::print(){
    
    map<int,list<int>>::iterator itr;
    for(itr = adj.begin();itr!=adj.end();itr++){
        cout << itr->first << "|->";
        for(auto each : itr->second){
            cout << each << "->";
        }
        cout << "/" << endl;
    }
}

void Graph::DFS_VISIT(int v){
    
    vis[v] = true;
    //? it will print the current node and look for the next vertex in adjacency list
    cout << v;
    
    for(auto each : adj[v]){
        if(!vis[each]){
            DFS_VISIT(each);
        }
    }
}

void Graph::DFS(){
    //? suppose if a node is isolated/disconnected then we need
    //? perform this for each vertex in graph G to make sure we 
    //? explored each vertex.
    for(auto each: adj){
        if(vis[each.first]!=true){
            DFS_VISIT(each.first);
        }
    }
}
int main(){

    Graph G;
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    
    G.print();
    G.DFS();

}
```

## Edge Classification

pg 609

![Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2019.png](Graphs%205f24ef0872a64779bfe1ff8cee26bb31/Untitled%2019.png)

**Tree Edges :** Those edges that were visited/discovered in the DFS tree. a→b→e→d

**Front Edges:** Edges from node to descendant i.e not part of the DFS tree. Eg: a→d

**Back Edges:** Edges from descendent i.e part of the DFS tree to an ancestor. Eg: d→b (part of the DFS tree)

**Cross Edges** : Other edges, as long as one vertex is not an ancestor of other all rest are cross edges. Eg e→d and e→g (they are not ancestors, they are siblings)

This edge classification is used in other applications like topological sort and cycle detection.

## Cycle Detection

Detecting whether a Directed has a cycle or not?

for undirected graphs?

An undirected graph will only have tree edges and back edges. No forward and cross edges.

**Lemma** : If there exist a back edge then there will be definitely a cycle present in Directed Graph ↔ If there exist a cycle there exist a back edge in the Directed Graph.

Using color scheme for visiting different edges.

WHITE - Indicates a tree edge

GREY - Indicates a back edge 

BLACK - Indicates a forward or cross edge

# Topological Sort

[https://www.youtube.com/watch?v=eL-KzMXSXXI](https://www.youtube.com/watch?v=eL-KzMXSXXI)

linear ordering of all the vertices s.t. if G contains an edge (u,v) then u appears before v in the ordering.

Used to order DAG, topological sort is not possible in acyclic graphs i.e if a cycle is present no ordering can be done.

It is not usual sorting which will arrange numerical values.

### Algorithm:

Topological Sort(G):

1. call DFS(G) to compute the finishing times f for each vertex.
2. as each vertex is finished, insert it onto front of a linked list.
3. return the linked list of vertices.

**Q: How to calculate finishing times?**

A: while running DFS-SPLIT we can find the time either by using clock_time or a counter.

**Q: Why at the front of the linked list?**

A: Because we don't want to spend time reversing the linked list for the correct.
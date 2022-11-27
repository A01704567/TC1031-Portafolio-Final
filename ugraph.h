/*
 * graph.h
 *
 *  Created on: 26/11/2022
 *      Author: SofíaBlancoPrigmore 
 */

#ifndef UGRAPH_H_
#define UGRAPH_H_

#include <sstream>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include "exception.h"
#include "header.h"

/***********************************************************/
/********************** UnweightedGraph ********************/
/***********************************************************/

template<class Vertex>
class UnweightedGraph {
public:
	virtual void addEdge(Vertex, Vertex) = 0;
	virtual bool containsVertex(Vertex) const = 0;
	virtual std::vector<Vertex> getVertexes() const = 0;
	virtual std::set<Vertex> getConnectionFrom(Vertex) const = 0;
	virtual std::string toString() const = 0;
};

//===============================================
//Declaration of Class UMatrixGraph 
//===============================================
template<class Vertex>
class UMatrixGraph : public UnweightedGraph<Vertex>{
private:
	int next, size;
	bool direction;
	std::vector<Vertex> vertexes;
	std::vector<std::vector<bool> > edges;

	int indexOf(Vertex v) const;

public:
	UMatrixGraph(int, bool dir = true);
	void addEdge(Vertex from, Vertex to);
	bool containsVertex(Vertex v) const;
	std::vector<Vertex> getVertexes() const;
	std::set<Vertex> getConnectionFrom(Vertex v) const;
	std::string toString() const;
    void loadGraph(std::fstream &);
};

//===============================================
// UMatrixGraph Constructor 
//===============================================
template <class Vertex>
UMatrixGraph<Vertex>::UMatrixGraph(int max, bool dir) {
	size = max;
	if (size == 0) {
        throw RangeError();
	}

	next = 0;
	direction = dir;
	vertexes.resize(size);
	edges.resize(size);
	for (int i = 0; i < size; i++) {
		edges[i].resize(size, false);
		edges[i][i] = true;
	}
}

//===============================================
//Index of a vertex v 
// vertex v 
//returns the index of the vertex 
//complexity O(n)
//===============================================
template <class Vertex>
int UMatrixGraph<Vertex>::indexOf(Vertex v) const {
	for (int i = 0; i < next; i++) {
		if (vertexes[i] == v) {
			return i;
		}
	}
	return -1;
}

//===============================================
// Add edge to a vertex 
//Parameter from = where the edge begins 
//Parameter to = where the edge ends 
//complexity:  O(n)
//===============================================
template <class Vertex>
void UMatrixGraph<Vertex>::addEdge(Vertex from, Vertex to) {
	int fp = indexOf(from);
	if (fp == -1) {
		if (next == size) {
			throw OutOfMemory();
		}

		vertexes[next++] = from;
		fp = next - 1;
	}

	int tp = indexOf(to);
	if (tp == -1) {
		if (next == size) {
			throw OutOfMemory();
		}

		vertexes[next++] = to;
		tp = next - 1;
	}

	edges[fp][tp] = true;
	if (!direction) {
		edges[tp][fp] = true;
	}
}

//===============================================
//Check if vertex in graph 
// returns true if vertex in graph, false if vertex not in graph 
//complexity: O(n)
//===============================================
template <class Vertex>
bool UMatrixGraph<Vertex>::containsVertex(Vertex v) const {
	return (indexOf(v) != -1);
}

//===============================================
//Gets vertexes 
//complexity O(n)
//===============================================
template <class Vertex>
std::vector<Vertex> UMatrixGraph<Vertex>::getVertexes() const {
	std::vector<Vertex> result(vertexes);
	return result;
}

//===============================================
//Gets vertex's connections 
// parameter v = the vertex 
// return connections 
//complexity: O(n)
//===============================================
template <class Vertex>
std::set<Vertex> UMatrixGraph<Vertex>::getConnectionFrom(Vertex v) const {
	int i = indexOf(v);
	if (i == -1) {
		throw NoSuchElement();
	}

	std::set<Vertex> result;
	for (int j = 0; j < next; j++) {
		if (i != j && edges[i][j]) {
			result.insert(vertexes[j]);
		}
	}
	return result;
}

//===============================================
//Obtains string representation of graph 
//returns string representation 
//complexity: O(n^2)
//===============================================
template <class Vertex>
std::string UMatrixGraph<Vertex>::toString() const {
	std::stringstream aux;

	for (int i = 0; i < next; i++) {
		aux << vertexes[i] << "\t";
		for (int j = 0; j < next; j++) {
			aux << edges[i][j] << "\t";
		}
		aux << "\n";
	}
	aux << "\n";
	return aux.str();
}

/***********************************************************/
/*****************  Function loadGraph  ********************/
/***********************************************************/
template <class Vertex>
void UMatrixGraph<Vertex>::loadGraph(std::fstream &inputfile){
    Vertex from, to; 
    while(inputfile >> from >> to){
        addEdge(from, to);
    }
}


/***********************************************************/
/**************************** DFS **************************/
/***********************************************************/

template <class Vertex>
std::set<Vertex> dfs(const Vertex& start,
	const UnweightedGraph<Vertex>* graph) {

	std::set<Vertex> visited;
	std::stack<Vertex> pending;
	typename std::set<Vertex>::iterator itr;

	pending.push(start);
	while (!pending.empty()) {
		Vertex v = pending.top(); pending.pop();
		if (visited.find(v) == visited.end()) {
			visited.insert(v);
			std::set<Vertex> connected =
					graph->getConnectionFrom(v);
			for (itr = connected.begin();
					itr != connected.end(); itr++) {
				pending.push( (*itr) );
			}
            std::cout << v << " " ; 
		}
	}
}


/***********************************************************/
/**************************** BFS **************************/
/***********************************************************/
template <class Vertex>
void bfs(const Vertex& start, const UnweightedGraph<Vertex>* graph) {
	std::set<Vertex> visited;
	std::queue<Vertex> pending;
	typename std::set<Vertex>::iterator itr;

	pending.push(start);
	while (!pending.empty()) {
		Vertex v = pending.front(); 
		pending.pop();
		if (visited.find(v) == visited.end()) {
			visited.insert(v);
			std::set<Vertex> connected = graph->getConnectionFrom(v);
			for (itr = connected.begin(); itr != connected.end(); itr++) {
				pending.push( (*itr) );
			}
			std::cout << v << " ";
		}
	}
}

#endif
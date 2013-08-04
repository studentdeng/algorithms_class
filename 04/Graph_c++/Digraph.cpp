//
//  Digraph.cpp
//  Graph_c++
//
//  Created by yg curer on 13-2-23.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#include "Digraph.h"
Digraph::Digraph(int V)
{
    this->vNum = V;
    this->eNum = 0;
    
    for (int v = 0; v < V; ++v) {
        NodeList nodeList;
        this->adj.push_back(nodeList);
    }
}

void Digraph::addEdge(int v, int w)
{
    if (this->adj.size() <= v) {
        this->adj.resize(v + 1);
    }
    
    if (adj[v].size() == 0) {
        this->vNum ++;
    }
    
    this->adj[v].push_back(w);
    this->eNum ++;
}

NodeList *Digraph::getNodeList(int v)
{
    return &this->adj[v];
}

Digraph Digraph::reverse()
{
    Digraph R;
    
    for (int v = 1; v < adj.size(); ++v) {
        /*
        for (int w = 0 ; w < this->adj[v].size(); ++w) {
            R.addEdge(w, v);
        }*/
        
        for (NodeList::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
            int value = *it;
            R.addEdge(value, v);
        }
    }
    
    R.vNum = this->vNum;
    
    return R;
}




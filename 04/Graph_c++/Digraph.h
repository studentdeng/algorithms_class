//
//  Digraph.h
//  Graph_c++
//
//  Created by yg curer on 13-2-23.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#ifndef __Graph_c____Digraph__
#define __Graph_c____Digraph__

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> NodeList;

class Digraph {
public:
    Digraph():vNum(0), eNum(0)
    {
    }
    
    Digraph(int V);
    
    ~Digraph()
    {
    }
    
    int V();
    int E();
    
    void addEdge(int v, int w);
    NodeList *getNodeList(int v);
    Digraph reverse();
    
    int vNum;
    int eNum;
    
    vector<NodeList> adj;
    
private:
    
};

#endif /* defined(__Graph_c____Digraph__) */

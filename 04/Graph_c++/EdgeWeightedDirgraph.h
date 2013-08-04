//
//  EdgeWeightedDirgraph.h
//  Graph_c++
//
//  Created by yg curer on 13-3-2.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#ifndef __Graph_c____EdgeWeightedDirgraph__
#define __Graph_c____EdgeWeightedDirgraph__

#include <iostream>
#include "DirectedEdge.h"
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<DirectedEdge> WeightedNodeList;

class EdgeWeightedDirgraph {
public:
    void addEdge(DirectedEdge e);
    
    map<int, WeightedNodeList> adj;
};

class DijkstraSP {
    void relax();
public:
    DijkstraSP(EdgeWeightedDirgraph &g, int s);
};

#endif /* defined(__Graph_c____EdgeWeightedDirgraph__) */

//
//  kosarajuSCC.h
//  Graph_c++
//
//  Created by yg curer on 13-2-23.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#ifndef __Graph_c____kosarajuSCC__
#define __Graph_c____kosarajuSCC__

#include <iostream>
#include <vector>
#include <deque>
#include "Digraph.h"

using namespace std;

class KosarajuSCC {
public:
    deque<int> stack;
    vector<bool>    marked;
    vector<int>     id;
    int count;
    
public:
    KosarajuSCC(Digraph &g):count(1)
    {
        marked.resize(g.vNum + 1);
    }
    
    void SCC(Digraph &g);
    void _dfs(Digraph &g, int v);
    void _dfs_stack(Digraph &g, int v);
};

#endif /* defined(__Graph_c____kosarajuSCC__) */

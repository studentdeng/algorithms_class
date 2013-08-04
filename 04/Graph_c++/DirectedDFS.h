//
//  DirectedDFS.h
//  Graph_c++
//
//  Created by yg curer on 13-2-23.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#ifndef __Graph_c____DirectedDFS__
#define __Graph_c____DirectedDFS__

#include <iostream>
#include <deque>
#include <list>
#include "Digraph.h"

class DirectedDFS {
    vector<bool> marked;
    
public:
    DirectedDFS():cout(0)
    {}
    ~DirectedDFS()
    {}
    void DFS(Digraph &g);
    void DFS_Stack(Digraph &g);
    void _dfs(Digraph &g, int v);
    
    deque<int> pre;
    deque<int> post;
    list<int> reversePost;
    
    vector<int> func;
    vector<int> leader;
    
    list<int> stack;
    
    int cout;
};

#endif /* defined(__Graph_c____DirectedDFS__) */

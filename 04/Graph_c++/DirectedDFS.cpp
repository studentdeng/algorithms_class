//
//  DirectedDFS.cpp
//  Graph_c++
//
//  Created by yg curer on 13-2-23.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#include "DirectedDFS.h"

void DirectedDFS::DFS(Digraph &g)
{
    this->marked.resize(g.vNum + 1);
    //func.resize(g.vNum + 1);
    reversePost.resize(g.vNum + 1);
    
    for (int i = 1; i < g.adj.size(); ++i) {
        if (!this->marked[i]) {
            this->_dfs(g, i);
        }
    }
}

void DirectedDFS::_dfs(Digraph &g, int v)
{   
    this->marked[v] = true;
    NodeList &list = g.adj[v];
    for (NodeList::iterator it = list.begin(); it != list.end(); ++it) {
        if (!this->marked[*it]) {
            this->_dfs(g, *it);
        }
    }
     
    this->cout++;
    reversePost.push_front(v);
}


void DirectedDFS::DFS_Stack(Digraph &g)
{
    reversePost.resize(g.vNum + 1, 0);
    this->marked.resize(g.vNum + 1, false);
    
    for (int i = 1; i < g.adj.size(); ++i) {
        if (!this->marked[i]) {
            stack.push_back(i);
            
            marked[i] = true;
            
            while (!stack.empty()) {
                int s = stack.back();
                
                NodeList &list = g.adj[s];
                
                bool bfind = false;
                
                for (NodeList::iterator it = list.begin(); it != list.end(); ++it) {
                    int test = *it;
                    if (!this->marked[test]) {
                        stack.push_back(test);
                        this->marked[test] = true;
                        
                        bfind = true;
                        
                        break;
                    }
                }
                
                if (!bfind) {
                    stack.pop_back();
                    
                    this->cout++;
                    reversePost.push_front(s);
                }
            }
        }
    }
}

//
//  kosarajuSCC.cpp
//  Graph_c++
//
//  Created by yg curer on 13-2-23.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#include "kosarajuSCC.h"
#include "DirectedDFS.h"

void KosarajuSCC::SCC(Digraph &g)
{
    DirectedDFS *order = new DirectedDFS();
    
    Digraph g2 = g.reverse();
    
    order->DFS_Stack(g2);
    //order->DFS(g2);
    
    this->marked.resize(g2.vNum * 2, false);
    id.resize(g2.vNum * 2);
    
    printf("2nd\n");
    
    /*
    for (deque<int>::iterator it = order->reversePost.begin(); it != order->reversePost.end(); ++it) {
        int test = *it;
        
        if (!this->marked[test] && test != 0) {
            this->_dfs(g, test);
            this->count ++;
        }
    }*/
    
    for (list<int>::iterator it = order->reversePost.begin(); it != order->reversePost.end(); ++it) {
        int test = *it;
        
        if (!this->marked[test] && test != 0) {
            this->_dfs_stack(g, test);
            this->count ++;
        }
    }
}

void KosarajuSCC::_dfs(Digraph &g, int v)
{
    this->marked[v] = true;
    id[v] = this->count;
    cout << "v = "<< v << "count = "<< this->count <<endl;
    
    NodeList &list = g.adj[v];
    
    for (NodeList::iterator it = list.begin(); it != list.end(); ++it) {
        if (!this->marked[*it]) {
            this->_dfs(g, *it);
        }
    }
}

void KosarajuSCC::_dfs_stack(Digraph &g, int v)
{
    this->marked.resize(g.vNum + 1, false);
    
    if (!this->marked[v]) {
        stack.push_back(v);
        
        marked[v] = true;
        
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
                
                id[s] = this->count;
                cout << "v = "<< s << "count = "<< this->count <<endl;
            }
        }
    }
}

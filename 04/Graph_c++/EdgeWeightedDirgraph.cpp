//
//  EdgeWeightedDirgraph.cpp
//  Graph_c++
//
//  Created by yg curer on 13-3-2.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#include "EdgeWeightedDirgraph.h"


void EdgeWeightedDirgraph::addEdge(DirectedEdge e)
{
    int from = e.from;
    
    adj[from].push_back(e);
}

class HeapNode {
    
    
public:
    HeapNode(int v, double distance):v(v), distance(distance)
    {}
    double distance;
    int v;
};

struct wedge_rank_greater_than {
    bool operator()(HeapNode const& a, HeapNode const& b) const {
        return a.distance > b.distance;
    }
};

DijkstraSP::DijkstraSP(EdgeWeightedDirgraph &g, int s)
{
    int MAX_DISTANCE = 1000000;
    vector<HeapNode> vHeapDistance;  //没有处理的到顶点的距离list
    vector<DirectedEdge> edgeToVList;
    vector<double> distanceResult;
    
    for (int i = 0 ; i <= g.adj.size() + 1; ++i) {
        vHeapDistance.push_back(HeapNode(i, MAX_DISTANCE));
    }
    
    distanceResult.resize(g.adj.size() + 1, MAX_DISTANCE);
    
    vHeapDistance[s].distance = 0;
    distanceResult[1] = 0;
    
    make_heap(vHeapDistance.begin(), vHeapDistance.end(), wedge_rank_greater_than());
    
    while (!vHeapDistance.empty()) {
        //取出一个离起点最近的
        HeapNode node = vHeapDistance.front();
        
        int v = node.v;
        for (WeightedNodeList::iterator it = g.adj[v].begin(); it != g.adj[v].end(); ++it) {
            DirectedEdge edge = *it;
            int w = edge.to;
            
            bool bFind = false;
            vector<HeapNode>::iterator findWItHeap = vHeapDistance.begin();
            for (vector<HeapNode>::iterator itHeap = vHeapDistance.begin(); itHeap != vHeapDistance.end(); ++itHeap) {
                if (itHeap->v == w) {
                    findWItHeap = itHeap;
                    bFind = true;
                    break;
                }
            }
            
            if (!bFind) {
                continue;
            }
            
            if (findWItHeap->distance > node.distance + edge.weight) {
                findWItHeap->distance = node.distance + edge.weight;
                
                if (edgeToVList.size() <= w) {
                    edgeToVList.resize(w + 1);
                }
                
                edgeToVList[w] = edge;
                
                distanceResult[w] = findWItHeap->distance;
            }
        }
        
        vHeapDistance.erase(vHeapDistance.begin());
        make_heap(vHeapDistance.begin(), vHeapDistance.end(), wedge_rank_greater_than());
    }
    
    vector<int> orderList;
    orderList.push_back(7);
    orderList.push_back(37);
    orderList.push_back(59);
    orderList.push_back(82);
    orderList.push_back(99);
    orderList.push_back(115);
    orderList.push_back(133);
    orderList.push_back(165);
    orderList.push_back(188);
    orderList.push_back(197);
    
    int i = 1;
    for (vector<double>::iterator it = distanceResult.begin() + 1; it != distanceResult.end(); ++it) {
        
        bool bFind = false;
        for (vector<int>::iterator itFind = orderList.begin(); itFind != orderList.end(); ++itFind) {
            if (*itFind == i) {
                bFind = true;
                break;
            }
        }
        
        if (bFind) {
            cout<<*it<<",";
        }
        ++i;
    }
}

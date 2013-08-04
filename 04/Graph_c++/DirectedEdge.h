//
//  DirectedEdge.h
//  Graph_c++
//
//  Created by yg curer on 13-3-2.
//  Copyright (c) 2013年 curer. All rights reserved.
//

#ifndef __Graph_c____DirectedEdge__
#define __Graph_c____DirectedEdge__

#include <iostream>

class DirectedEdge {
public:
    
    DirectedEdge(int from, int to, double weight):from(from), to(to), weight(weight)
    {
    }
    
    DirectedEdge():from(0), to(0), weight(0)
    {
    }
    
    double weight;
    int from;
    int to;
};

#endif /* defined(__Graph_c____DirectedEdge__) */

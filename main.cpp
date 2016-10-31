#include <iostream>
#include <stack>
#include "Stack.h"

/**
 * @param affected true if previous canal is affected
 */
struct canal {
    int end_lake_label;
    bool affected;
    canal *next;
};

struct lake {
    int index;
    int lowlink;
    int cost;
    canal *descendant;
};

int globalIndex = 0;

Stack* stack;


int tarjan(lake& node) {

    globalIndex++;
    node.index = globalIndex;
    node.lowlink = globalIndex;
    stack->push(node.index);

    return 2;

};

int main() {

    int N, M;
    canal* canals;
    lake* lakes;

    std::cin >> N;
    std::cin >> M;

    // allocating N lakes
    lakes = new lake[N];
    // allocating M canals
    canals = new canal[M];
    // create global stack
    stack = new Stack(N);

    int start, finish;
    bool affected;
    for(int i=0; i<M; i++) {

        std::cin >> start;
        std::cin >> finish;
        std::cin >> affected;

        canals[i].end_lake_label = finish;
        canals[i].affected = affected;

        if(lakes[start].descendant == NULL) {
            lakes[start].descendant = &canals[i];
        } else {
            canal *cur = lakes[start].descendant;
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = &canals[i];
        }


    }

    int max = 0;
    for(int i=0; i < N; i++) {
        if(lakes[i].index == 0) {
            int c = tarjan(lakes[i]);
            max = (c > max) ? c : max;
        }
    }

    std::cout << max << std::endl;
    

    /*
    for(int i=0; i < N; i++) {
        std::cout << i << ":";

        canal *c = lakes[i].descendant;
        do {
            std::cout << " -> " << c->end_lake_label << "," << c->affected;
            c = c->next;
        }
        while(c != NULL);
        std::cout << std::endl;
    }
    */



    delete canals;
    delete lakes;

    return 0;
}
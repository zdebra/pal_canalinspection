#include <iostream>
#include <stack>
#include "Stack.h"

/**
 * @param affected true if previous canal is affected
 */
struct Edge {
    int end_lake_label;
    bool affected;
    Edge *next;
};

struct Node {
    int index;
    int lowlink;
    int cost;
    Edge *descendant;
};

int globalIndex = 0;

Stack* stack;
Node* lakes;

int min(int a, int b) {
    if(a<=b) return a;
    return b;
}

int tarjan(Node& node, int label) {

    globalIndex++;
    node.index = globalIndex;
    node.lowlink = globalIndex;
    stack->push(label);

    // for each node descendant
    Edge* d = node.descendant;
    int max = 0;
    while(d != NULL) {

        // node wasn't touched yet
        if(lakes[d->end_lake_label].index == 0) {
            tarjan(lakes[d->end_lake_label], d->end_lake_label);
            node.lowlink = min(lakes[d->end_lake_label].lowlink, node.lowlink);
        }

        // scc wasn't closed yet
        else if(stack->contains(d->end_lake_label)) {
            node.lowlink = min(node.lowlink,lakes[d->end_lake_label].index);

        }

        // scc closed
        else {

        }

        d = d->next;
    }

    if(node.lowlink == node.index) {

        std::cout << "Found SCC: ";
        int cur;
        do {
            cur = stack->pop();
            std::cout << cur << ", ";

        } while(cur != label && cur != -1);

        std::cout << std::endl;
    }

    return max;


};

int main() {

    int N, M;
    Edge* canals;

    std::cin >> N;
    std::cin >> M;

    // allocating N lakes
    lakes = new Node[N];
    // allocating M canals
    canals = new Edge[M];
    // create global stack
    stack = new Stack(M);

    int start, finish;
    bool affected;
    for(int i=0; i<M; ++i) {

        std::cin >> start;
        std::cin >> finish;
        std::cin >> affected;

        canals[i].end_lake_label = finish;
        canals[i].affected = affected;

        if(lakes[start].descendant == NULL) {
            lakes[start].descendant = &canals[i];
        } else {
            Edge* cur = lakes[start].descendant;
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = &canals[i];
        }


    }

    int max = 0;
    for(int i=0; i < N; i++) {
        if(lakes[i].index == 0) {
            int c = tarjan(lakes[i], i);
            max = (c > max) ? c : max;
        }
    }

    std::cout << max << std::endl;

    /*
    for(int i=0; i < N; i++) {
        std::cout << i << ":";

        Edge *c = lakes[i].descendant;
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
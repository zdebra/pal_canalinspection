#include <iostream>
#include <stack>
#include "Stack.h"

/**
 * Slightly improved version of tarjan algorithm (better DFS) for finding strongly connected components (SSC) in oriented graph.
 *
 * Tarjan algorithm: @{link https://www.algoritmy.net/article/1515/Tarjanuv-algoritmus}
 * Task: https://cw.felk.cvut.cz/courses/a4m33pal/task.php?task=canalsinspection
 *
 * It does only single traversion through the graph, thus O(V+E).
 *
 * It reads data from stdin as is defined in assignment.
 *
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
    int back_cost;
    Edge *descendant;
};

int globalIndex = 0;

Stack* stack;
Node* lakes;

int min(int a, int b) {
    if(a<=b) return a;
    return b;
}

int max(int a, int b) {
    if(a >= b) return a;
    return b;
}

void tarjan(Node& node, int label) {

    globalIndex++;
    node.index = globalIndex;
    node.lowlink = globalIndex;
    stack->push(label);

    // for each node's descendant
    Edge* d = node.descendant;
    while(d != NULL) {

        // node wasn't touched yet
        if(lakes[d->end_lake_label].index == 0) {
            tarjan(lakes[d->end_lake_label], d->end_lake_label);

            // there is a back edge further this way
            if(lakes[d->end_lake_label].lowlink < lakes[d->end_lake_label].index) {
                node.back_cost += lakes[d->end_lake_label].back_cost + d->affected;
                node.cost = max(node.cost,lakes[d->end_lake_label].cost);
                node.lowlink = min(node.lowlink, lakes[d->end_lake_label].lowlink);
            }
            // the road is closing further this way
            else {
                node.cost = max(node.cost,lakes[d->end_lake_label].cost + d->affected);
            }

        }

        // scc wasn't closed yet
        else if(stack->contains(d->end_lake_label)) {
            node.lowlink = min(node.lowlink,lakes[d->end_lake_label].index);
            node.back_cost += d->affected;
        }

        // scc closed
        else {
            node.cost = max(node.cost, lakes[d->end_lake_label].cost + d->affected);
        }

        d = d->next;
    }

    if(node.lowlink == node.index) {

        node.cost += node.back_cost;

        // pop from stack until root is reached (and those poped nodes are members of SCC)
        int cur;
        do {
            cur = stack->pop();
            lakes[cur].cost = node.cost;


        } while(cur != label && cur != -1);

    }

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
    stack = new Stack(N);

    // retrieve data from stdin and create graph representation
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

    // run tarjan for each node which wasn't visited yet
    int max = 0;
    for(int i=0; i < N; i++) {
        if(lakes[i].index == 0) {
            tarjan(lakes[i], i);
            max = (lakes[i].cost > max) ? lakes[i].cost : max;
        }
    }

    std::cout << max << std::endl;

    delete canals;
    delete lakes;

    return 0;
}
#include <iostream>

/**
 * @param affected true if previous canal is affected
 */
struct canal {
    int end_lake_label;
    bool affected;
    canal *next;
};

int main() {

    int N, M;
    canal* canals;
    canal** lakes;

    std::cin >> N;
    std::cin >> M;

    // allocating N lakes
    lakes = (canal**) malloc(sizeof(canal*)*N);
    if (lakes==NULL) exit (1);

    // allocating M canals
    canals = (canal*) malloc(sizeof(canal)*M);
    if (canals==NULL) exit (1);

    int start, finish;
    bool affected;
    for(int i=0; i<M; i++) {

        std::cin >> start;
        std::cin >> finish;
        std::cin >> affected;

        canals[i].end_lake_label = finish;
        canals[i].affected = affected;

        if(lakes[start] == NULL) {
            lakes[start] = &canals[i];
        } else {
            canal *cur = lakes[start];
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = &canals[i];
        }


    }


    /*
    for(int i=0; i < N; i++) {
        std::cout << i << ":";

        canal *c = lakes[i];
        do {
            std::cout << " -> " << c->end_lake_label << "," << c->affected;
            c = c->next;
        }
        while(c != NULL);
        std::cout << std::endl;
    }
    */

    return 0;
}
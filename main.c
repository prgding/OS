#include <math.h>
#include "process.h"
#include "thread.h"
#include "monte_carlo.h"
#include "monte_carlo_multitasks.h"

int main(int argc, char const *argv[]) {
    clock_t start, delta;
    start = clock();

    for (int i = 0; i < 6; ++i) {
//        monte_carlo_multitasks(pow(10, i));
        monte_carlo_multitasks(2000 * (i + 1));
    }

    delta = clock() - start;

    printf("Total time : %lf seconds\n", (double) delta / CLOCKS_PER_SEC);
    return 0;

}


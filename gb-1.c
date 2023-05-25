#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PEGS 10
#define BINS (PEGS + 1)

int main() {
    // Galton Board Simulation with 100 balls

    int bins[BINS] = {0};  // Initialize bins to 0

    srand(time(NULL));  // Seed the random number generator with the current time

    int numBalls = 100;

    // Simulate the dropping of balls through the Galton Board
    for (int i = 0; i < numBalls; i++) {
        int position = 0;  // Starting position at the top

        // Determine the path of the ball through the pegs
        for (int j = 0; j < PEGS; j++) {
            if (rand() % 2 == 0) {
                position++;  // Move to the right
            } else {
                position--;  // Move to the left
            }
        }

        // Adjust position to ensure it falls within the valid bin range
        if (position < 0) {
            position = 0;
        } else if (position >= BINS) {
            position = BINS - 1;
        }

        bins[position]++;  // Increment the corresponding bin
    }

    // Print the distribution of balls in the bins
    printf("Bins:\n");
    for (int i = 0; i < BINS; i++) {
        printf("%2d: %d\n", i, bins[i]);
    }

    return 0;
}

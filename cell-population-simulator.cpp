#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits> 
using namespace std;

// Function to check if a cell is surrounded by two populated cells
bool checkSurroundings(const vector<int>& community, int index) {
    if (index < 1 || index >= community.size() - 1)
        return false; // Cell is at the edge of the community

    return community[index - 1] == 1 && community[index + 1] == 1;
  
    // Function to check if a cell is surrounded by two populated cells
    // Parameters:
    // - community: vector representing the community
    // - index: index of the cell in consideration
    // Returns: true if the cell is surrounded by two populated cells, false otherwise
}

// Function to simulate the evolution of the community
int evolveCommunity(int n, int k) {
    vector<int> community(n, 0); // Initialize community with unpopulated cells
    int populatedCells = 0;
    int steps = 0;
  


    // Randomly populate k cells
    srand(time(0)); // Seed for random number generation
    while (populatedCells < k) {
        int index = rand() % n;
        if (community[index] == 0) {
            community[index] = 1;
            populatedCells++;
        }
    }
    /*
    This part of program simulates the evolution of a community where initially some cells are populated randomly.
    The community evolves by adding new cells randomly and applying a conversion rule when specific conditions are met.
    The goal is to fully populate the community by adding new cells efficiently.
    */

    // Continue evolving until all cells are populated
    while (populatedCells < n) {
        // Add a randomly selected cell
        int index = rand() % n;
        if (community[index] == 0) {
            community[index] = 1;
            populatedCells++;
            steps++;

            // Apply the C to D conversion rule
            for (int i = 1; i < n - 1; ++i) {
                if (community[i] == 0 && checkSurroundings(community, i)) {
                    community[i] = 1;
                    populatedCells++;
                    steps++;
                }
            }
        }
    }

    return steps;
}

int main() {
    int n = 10; // Number of cells
    int k = 3; // Initially populated cells

    int minSteps = INT_MAX;
    int maxSteps = INT_MIN;
    int numTrials = 1000;

    // Perform multiple trials to find minimum and maximum steps
    for (int i = 0; i < numTrials; ++i) {
        int steps = evolveCommunity(n, k);
        minSteps = min(minSteps, steps);
        maxSteps = max(maxSteps, steps);
    }
    /*
    This program simulates the evolution of a community by randomly populating cells and applying conversion rules.
    It aims to fully populate the community efficiently.
    */ 
    cout << "Minimum steps to fully populate: " << minSteps << endl;
    cout << "Maximum steps to fully populate: " << maxSteps << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a struct for holding asset information
struct Asset {
    string name;
    double volatility; // Placeholder for volatility measure
    double current_weight; // Current weight in the portfolio
    double target_weight; // Target weight in the portfolio
};

// Function to calculate weights based on risk parity
vector<double> calculateWeights(const vector<Asset>& assets) {
    vector<double> weights;
    double total_volatility = 0.0;

    // Calculate total volatility
    for (const auto& asset : assets) {
        total_volatility += asset.volatility;
    }

    // Calculate weights based on risk parity (equal risk contribution)
    for (const auto& asset : assets) {
        double weight = asset.volatility / total_volatility;
        weights.push_back(weight);
    }

    return weights;
}

// Function to simulate rebalancing
void rebalancePortfolio(vector<Asset>& assets) {
    // Calculate current total value of the portfolio
    double total_value = 0.0;
    for (const auto& asset : assets) {
        total_value += asset.current_weight;
    }

    // Rebalance each asset to its target weight
    for (auto& asset : assets) {
        double target_value = total_value * asset.target_weight;

        // Adjust current weight towards target weight
        asset.current_weight = target_value;
    }
}

int main() {
    // Define assets (for demonstration, simplifying with dummy data)
    vector<Asset> assets = {
        {"Stocks", 0.15, 0.15, 0.20}, // Current weight 15%, Target weight 20%
        {"Bonds", 0.08, 0.08, 0.15},  // Current weight 8%, Target weight 15%
        {"Gold", 0.12, 0.12, 0.10},   // Current weight 12%, Target weight 10%
        {"Commodities", 0.10, 0.10, 0.10}, // Current weight 10%, Target weight 10%
        {"Real Estate", 0.18, 0.18, 0.20}, // Current weight 18%, Target weight 20%
        {"Inflation-Linked Bonds", 0.05, 0.05, 0.05} // Current weight 5%, Target weight 5%
    };

    // Calculate initial weights based on risk parity
    vector<double> weights = calculateWeights(assets);

    // Output initial weights
    cout << "Initial Weights:" << endl;
    for (size_t i = 0; i < assets.size(); ++i) {
        cout << assets[i].name << ": " << assets[i].current_weight * 100 << "%" << endl;
    }

    // Simulate rebalancing (adjusting current weights towards target weights)
    rebalancePortfolio(assets);

    // Output rebalanced weights
    cout << "\nRebalanced Weights:" << endl;
    for (size_t i = 0; i < assets.size(); ++i) {
        cout << assets[i].name << ": " << assets[i].current_weight * 100 << "%" << endl;
    }

    return 0;
}

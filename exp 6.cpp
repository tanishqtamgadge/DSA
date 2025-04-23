#include <iostream>
#include <unordered_map>
#include <list>
#include <unordered_set>
using namespace std;

class FlightGraph {
private:
    unordered_map<string, list<pair<string, int>>> adjList;

public:
    // Add edge (flight) between cities
    void addFlight(string from, string to, int time) {
        adjList[from].push_back({to, time});
        adjList[to].push_back({from, time}); // Undirected graph
    }

    // Display the graph
    void displayGraph() {
        cout << "Flight Connections (Adjacency List):\n";
        for (auto& city : adjList) {
            cout << city.first << " -> ";
            for (auto& edge : city.second) {
                cout << "(" << edge.first << ", " << edge.second << "h) ";
            }
            cout << endl;
        }
    }

    // DFS utility to check connectivity
    void dfs(string city, unordered_set<string>& visited) {
        visited.insert(city);
        for (auto& neighbor : adjList[city]) {
            if (visited.find(neighbor.first) == visited.end()) {
                dfs(neighbor.first, visited);
            }
        }
    }

    // Check if graph is connected
    bool isConnected() {
        if (adjList.empty()) return true;

        unordered_set<string> visited;
        string start = adjList.begin()->first;
        dfs(start, visited);

        return visited.size() == adjList.size();
    }
};

// Main function
int main() {
    FlightGraph graph;

    // Add sample flight connections
    graph.addFlight("A", "B", 2);
    graph.addFlight("A", "C", 3);
    graph.addFlight("B", "C", 1);
    graph.addFlight("C", "D", 4);
    graph.addFlight("D", "E", 2);

    // Display graph
    graph.displayGraph();

    // Check connectivity
    if (graph.isConnected()) {
        cout << "\nThe flight network is CONNECTED.\n";
    } else {
        cout << "\nThe flight network is NOT connected.\n";
    }

    return 0;
}

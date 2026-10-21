#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

// Unit 5 Case Study A: City navigation using a weighted graph.
// Dijkstra's algorithm finds the shortest route for non-negative road distances.

struct Edge {
    int to;
    int weight;
};

class CityMap {
private:
    vector<string> places;
    vector<vector<Edge>> graph;

public:
    explicit CityMap(const vector<string>& names) : places(names), graph(names.size()) {}

    void addRoad(int a, int b, int distance) {
        if (a < 0 || b < 0 || a >= (int)places.size() ||
            b >= (int)places.size() || distance < 0) {
            cout << "Invalid road details.\\n";
            return;
        }
        graph[a].push_back({b, distance});
        graph[b].push_back({a, distance}); // Two-way road
    }

    void displayPlaces() const {
        cout << "\\nCity places:\\n";
        for (size_t i = 0; i < places.size(); ++i)
            cout << i << ". " << places[i] << '\\n';
    }

    void displayRoads() const {
        cout << "\\nRoad connections (distance units):\\n";
        for (size_t u = 0; u < graph.size(); ++u) {
            for (const Edge& e : graph[u]) {
                if ((int)u < e.to)
                    cout << places[u] << " <-> " << places[e.to]
                         << " : " << e.weight << '\\n';
            }
        }
    }

    void shortestRoute(int source, int destination) const {
        int n = (int)places.size();
        if (source < 0 || destination < 0 || source >= n || destination >= n) {
            cout << "Invalid place number.\\n";
            return;
        }

        const int INF = numeric_limits<int>::max() / 4;
        vector<int> dist(n, INF), parent(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [currentDistance, u] = pq.top();
            pq.pop();

            if (currentDistance != dist[u]) continue;
            for (const Edge& edge : graph[u]) {
                if (dist[u] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[u] + edge.weight;
                    parent[edge.to] = u;
                    pq.push({dist[edge.to], edge.to});
                }
            }
        }

        if (dist[destination] == INF) {
            cout << "No route exists between these places.\\n";
            return;
        }

        vector<int> route;
        for (int v = destination; v != -1; v = parent[v])
            route.push_back(v);
        reverse(route.begin(), route.end());

        cout << "Shortest distance: " << dist[destination] << " units\\n";
        cout << "Route: ";
        for (size_t i = 0; i < route.size(); ++i) {
            if (i) cout << " -> ";
            cout << places[route[i]];
        }
        cout << '\\n';
    }
};

int main() {
    vector<string> places = {
        "College", "Library", "Hospital", "Market", "Bus Station", "Park"
    };
    CityMap city(places);

    // Sample undirected weighted roads
    city.addRoad(0, 1, 4);
    city.addRoad(0, 3, 7);
    city.addRoad(1, 2, 5);
    city.addRoad(1, 3, 2);
    city.addRoad(2, 4, 3);
    city.addRoad(3, 4, 4);
    city.addRoad(3, 5, 6);
    city.addRoad(4, 5, 2);

    int choice;
    do {
        cout << "\\n===== CITY GPS / NAVIGATION SYSTEM =====\\n";
        cout << "1. Display places\\n2. Display roads\\n3. Find shortest route\\n0. Exit\\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) return 0;

        if (choice == 1) {
            city.displayPlaces();
        } else if (choice == 2) {
            city.displayRoads();
        } else if (choice == 3) {
            city.displayPlaces();
            int source, destination;
            cout << "Enter source place number: ";
            cin >> source;
            cout << "Enter destination place number: ";
            cin >> destination;
            city.shortestRoute(source, destination);
        } else if (choice != 0) {
            cout << "Invalid choice.\\n";
        }
    } while (choice != 0);

    cout << "Navigation system closed.\\n";
    return 0;
}

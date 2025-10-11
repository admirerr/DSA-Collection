#include <bits/stdc++.h>
using namespace std;

// Aliases for cleaner code
using int2 = pair<int,int>;          // (price, shop)
using int3 = tuple<int,int,int>;     // (price, shop, movie)

class MovieRentingSystem {
public:
    unordered_map<uint64_t,int> Shop;        // (shop,movie) -> price
    unordered_map<int,set<int2>> Movie;      // movie -> set of (price, shop)
    set<int3> rented;                        // rented movies -> set (price, shop, movie)

    // Utility to generate a unique key for (shop, movie)
    static inline uint64_t key(int shop,int movie) {
        return (uint64_t)shop << 32 | movie;
    }

    // Constructor: initialize shop/movie data
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Shop[key(shop, movie)] = price;
            Movie[movie].insert({price, shop});
        }
    }

    // Search for the 5 cheapest shops that have the given movie available
    vector<int> search(int movie) {
        vector<int> ans;
        auto& S = Movie[movie];
        int i = 0;
        for (auto it = S.begin(); it != S.end() && i < 5; it++, i++) {
            ans.push_back(it->second); // shop
        }
        return ans;
    }

    // Rent a movie from a shop
    void rent(int shop,int movie) {
        int price = Shop[key(shop,movie)];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    // Drop (return) a rented movie back to shop
    void drop(int shop,int movie) {
        int price = Shop[key(shop,movie)];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    // Report the 5 cheapest rented movies (shop, movie)
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i = 0;
        for (auto it = rented.begin(); it != rented.end() && i < 5; it++, i++) {
            auto [price, shop, movie] = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};

int main() {
    // Example input: 3 shops, 3 movies
    vector<vector<int>> entries = {
        {0, 1, 5},   // shop 0 rents movie 1 at price 5
        {0, 2, 6},   // shop 0 rents movie 2 at price 6
        {0, 3, 7},   // shop 0 rents movie 3 at price 7
        {1, 1, 4},   // shop 1 rents movie 1 at price 4
        {2, 1, 5}    // shop 2 rents movie 1 at price 5
    };

    MovieRentingSystem mrs(3, entries);

    // Search cheapest shops for movie 1
    auto res1 = mrs.search(1);
    cout << "Search movie 1: ";
    for (int shop : res1) cout << shop << " ";
    cout << endl;

    // Rent movie 1 from shop 1
    mrs.rent(1, 1);

    // Report rented movies
    auto res2 = mrs.report();
    cout << "Report rented: ";
    for (auto &v : res2) cout << "(" << v[0] << "," << v[1] << ") ";
    cout << endl;

    // Drop movie 1 back to shop 1
    mrs.drop(1, 1);

    // Report again
    auto res3 = mrs.report();
    cout << "Report rented after drop: ";
    for (auto &v : res3) cout << "(" << v[0] << "," << v[1] << ") ";
    cout << endl;

    return 0;
}

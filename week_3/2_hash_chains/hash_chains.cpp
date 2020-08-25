#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    vector<vector<string>> chain;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) 
    {
        chain=vector<vector<string>>(bucket_count);
    }

    Query readQuery() const 
    {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(chain[query.ind].size()) - 1; i >= 0; --i)
               // if (sort[hash_func(query.s)][i] == query.ind)
                    std::cout <<chain[query.ind][i] << " ";
            std::cout << "\n";
        } else {
            vector<string>::iterator it = std::find(chain[hash_func(query.s)].begin(), chain[hash_func(query.s)].end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != chain[hash_func(query.s)].end());
            else if (query.type == "add") 
            {
                if (it == chain[hash_func(query.s)].end())
                   chain[hash_func(query.s)].push_back(query.s);
            } 
            else if (query.type == "del") 
            {
                if (it != chain[hash_func(query.s)].end())
                    chain[hash_func(query.s)].erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

class DFS
{
public:
    using Graph = unordered_map<string, vector<string> >;

    vector<string> search(const Graph &graph, const string &startNode)
    {
        foundNodes.clear();
        dfs(graph, startNode);
        return foundNodes;
    }

private:
    vector<string> foundNodes;

    template <typename Container, typename T>
    bool contains(const Container &container, const T &value)
    {
        for (const auto &elem : container)
        {
            if (elem == value)
            {
                return true;
            }
        }
        return false;
    }

    void dfs(const Graph &graph, const string &node)
    {
        if (!contains(foundNodes, node))
        {
            foundNodes.push_back(node);
            // graph.at(node) throws out of bound if nod not contained while graph[node] would add a new one
            for (const string &neighbor : graph.at(node))
            {
                if (!contains(foundNodes, neighbor))
                {
                    dfs(graph, neighbor);
                }
            }
        }
    }
};

int main()
{
    DFS::Graph graph = {
        {"A", {"B", "C", "G"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F","G"}},
        {"F", {}},
        {"G", {}}
    };
    DFS dfs;
    vector<string> result = dfs.search(graph, "A");

    for (const auto &node : result)
    {
        cout << node << " - ";
    }
    cout << "\n" << "✅done! :R\n";

    return 0;
}
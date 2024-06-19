#include <iostream>
#include <vector>

bool isSafe(int v, std::vector<std::vector<int>>& graph, std::vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(std::vector<std::vector<int>>& graph, std::vector<int>& path, int pos) {
    if (pos == graph.size()) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < graph.size(); v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamCycle(std::vector<std::vector<int>>& graph) {
    std::vector<int> path(graph.size(), -1);

    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false) {
        std::cout << "Solução não existe\n";
        return false;
    }

    std::cout << "Solucao Existe: Segue um Ciclo Hamiltoniano\n";
    for (int i = 0; i < graph.size(); i++)
        std::cout << path[i] << " ";

    std::cout << path[0] << " ";
    std::cout << std::endl;

    return true;
}

int main() {    
    std::vector<std::vector<int>> graph = {

        {0, 1, 1, 1}, 
        {1, 0, 1, 1}, 
        {1, 1, 0, 1}, 
        {1, 1, 1, 0}
    };

    hamCycle(graph);

    return 0;
}

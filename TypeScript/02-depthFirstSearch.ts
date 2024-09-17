type Graph = Record<string, string[]>;
class DFS {
    public search(graph: Graph, node: string, found_nodes: (string)[]) {
        console.log(node);
        if (!found_nodes.includes(node)) {
            found_nodes.push(node)
            for (const neighbor of graph[node]) {
                this.search(graph, neighbor, found_nodes)
            }
            if (Object.keys(graph).length == found_nodes.length) {
                return found_nodes
            }
        }
    }
}

class DFS2 {
    private foundNodes: string[] = [];

    public search(graph: Graph, startNode: string): string[] {
        this.foundNodes = [];
        this.dfs(graph, startNode);
        return this.foundNodes;
    }

    private dfs(graph: Graph, node: string): void {
        if (!this.foundNodes.includes(node)) {
            console.log(node);
            this.foundNodes.push(node);
            for (const neighbor in graph[node]) {
                this.dfs(graph, neighbor);
            }
        }
    }
}


// Usage Example
const graph: Graph = {
    A: ['B', 'C', 'G'],
    B: ['D', 'E'],
    C: ['F'],
    D: [],
    E: ['F','G'],
    F: [],
    G: []
};

const dfs = new DFS();
const dfs2 = new DFS2();

const result = dfs.search(graph,'A',[]);
const result2 = dfs2.search(graph,'A');

console.log(graph);
console.log(result); // Output: ['A', 'B', 'D', 'E', 'C', 'F']
console.log(result2); // Output: ['A', 'B', 'D', 'E', 'C', 'F']

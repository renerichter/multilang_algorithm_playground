package main

import (
	"fmt"
)
// Graph is a map where the key is a node and the value is a list of neighbors.
type Graph map[string][]string;

type DFS struct{
	foundNodes []string;
}

// attach Search-method to DFS-struct to be able to eg manipulate fields of struct like foundNodes; and more efficient
func (dfs *DFS) Search(graph Graph, startNode string) []string{
	dfs.foundNodes = []string{} // reset for fresh search
	// if size known a priori
	// dfs.foundNodes = make([]string, 0, estimatedSize)
	dfs.dfs(graph,startNode)
	return dfs.foundNodes
}

func (dfs *DFS) dfs(graph Graph, node string){
	if !dfs.contains(node){
		// append operates in-place in dfs.foundNodes still has capacity
		dfs.foundNodes = append(dfs.foundNodes,node)
		for _,neighbor := range graph[node]{
			dfs.dfs(graph,neighbor)
		}
	}
}

func (dfs *DFS) contains(node string) bool{
	for _,n := range dfs.foundNodes{
		if n == node{
			return true
		}
	}
	return false
}

func main(){
	graph := Graph{
		"A": {"B","C","G"},
		"B": {"D", "E"},
		"C": {"F"},
		"D": {},
		"E": {"F","G"},
		"F": {},
		"G": {},
	}

	dfs := DFS{}
	result := dfs.Search(graph, "A")

	fmt.Println("DFS Traversal:", result) // Output: ["A", "B", "D", "E", "C", "F"]
}

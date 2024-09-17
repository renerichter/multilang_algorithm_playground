from typing import Any, Dict, List


class DFS:
    def search(self,graph:Dict[str,Any],v:str,found_nodes:List[str])->List[str]:
        if not v in found_nodes:
            found_nodes.append(v)
            for u in graph[v]:
                self.search(graph,u,found_nodes)
        if len(graph)==len(found_nodes):
            return found_nodes
        
    def search2(self,graph:Dict[str,Any], node:str, visited:set[Any]|None):
        if visited is None:
            visited = set()  # Use a set to track visited nodes
        
        if node not in visited:
            print(node)  # You can replace this with any action you want to perform on the node
            visited.add(node)
            
            for neighbor in graph[node]:
                self.search2(graph, neighbor, visited)
        if len(visited) == len(graph):
            return visited

                
                
        

if __name__ == '__main__':
    graph:Dict[str,Any] = {
        'A': ['B', 'C','G'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': [],
        'E': ['F','G'],
        'F': [],
        'G': []
    }
    dfs=DFS()
    a=dfs.search(graph,'A',[]) # order of my solution better
    b=dfs.search2(graph,'A',None)
    print(a)
    print(b)
    print("nice")

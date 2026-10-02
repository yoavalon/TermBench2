import Foundation

func dfs(graph: [String: [String]], start: String, end: String, visited: inout Set<String>) -> [String]? {
    if visited.contains(start) {
        return nil
    }
    visited.insert(start)
    if start == end {
        return [start]
    }
    for neighbor in graph[start, default: []] {
        if !visited.contains(neighbor) {
            if let path = dfs(graph: graph, start: neighbor, end: end, visited: &visited) {
                return [start] + path
            }
        }
    }
    return nil
}

func shortestPath(graph: [String: [String]], start: String, end: String) -> Int {
    var visited = Set<String>()
    if let path = dfs(graph: graph, start: start, end: end, visited: &visited) {
        return path.count - 1
    }
    return -1
}

let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": ["G"], "E": ["G"], "F": ["G"], "G": []]
let startNode = "A"
let endNode = "G"
let result = shortestPath(graph: graph, start: startNode, end: endNode)
print(result)
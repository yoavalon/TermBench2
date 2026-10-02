import Foundation

func dfs(graph: [String: [String]], start: String, end: String, path: [String], visited: Set<String>) -> [String]? {
    var newPath = path + [start]
    var newVisited = visited
    newVisited.insert(start)
    if start == end {
        return newPath
    }
    for neighbor in graph[start, default: []] {
        if !newVisited.contains(neighbor) {
            if let result = dfs(graph: graph, start: neighbor, end: end, path: newPath, visited: newVisited) {
                return result
            }
        }
    }
    return nil
}

func shortestPath(graph: [String: [String]], start: String, end: String) -> [String] {
    if let path = dfs(graph: graph, start: start, end: end, path: [], visited: Set()) {
        return path
    } else {
        return []
    }
}

var graph: [String: [String]] = [:]
graph["A", default: []].append(contentsOf: ["B", "C"])
graph["B", default: []].append(contentsOf: ["C", "D"])
graph["C", default: []].append(contentsOf: ["D"])
graph["D", default: []].append("E")
let start = "A"
let end = "E"
let result = shortestPath(graph: graph, start: start, end: end)
print(result)
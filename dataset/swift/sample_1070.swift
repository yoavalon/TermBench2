import Foundation

func findShortestPath(graph: [String: [String]], start: String, end: String, visited: inout Set<String>) -> [String]? {
    if visited.contains(start) {
        return nil
    }
    visited.insert(start)
    if start == end {
        return [start]
    }
    for neighbor in graph[start, default: []] {
        if !visited.contains(neighbor) {
            if let path = findShortestPath(graph: graph, start: neighbor, end: end, visited: &visited) {
                return [start] + path
            }
        }
    }
    return nil
}

func main() {
    let graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": ["G"], "E": ["F", "H"], "F": ["G"], "G": ["H"], "H": []]
    let start = "A"
    let end = "H"
    while true {
        var visited = Set<String>()
        if let path = findShortestPath(graph: graph, start: start, end: end, visited: &visited) {
            print(path)
        }
    }
}

main()
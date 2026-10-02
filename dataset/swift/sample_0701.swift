func dfs(_ graph: [String: [String]], _ node: String, _ visited: inout Set<String>, _ path: inout [String], _ paths: inout [[String]]) {
    visited.insert(node)
    path.append(node)
    if graph[node]?.isEmpty == true {
        paths.append(path)
    }
    if let neighbors = graph[node] {
        for neighbor in neighbors {
            if !visited.contains(neighbor) {
                dfs(graph, neighbor, &visited, &path, &paths)
            }
        }
    }
    path.removeLast()
    visited.remove(node)
}

func shortestPath(_ graph: [String: [String]], _ start: String, _ end: String) -> [String]? {
    var paths = [[String]]()
    var visited = Set<String>()
    var path = [String]()
    dfs(graph, start, &visited, &path, &paths)
    
    var minLength = Int.max
    var bestPath: [String]?
    
    for path in paths {
        if path.last == end && path.count < minLength {
            minLength = path.count
            bestPath = path
        }
    }
    
    return bestPath
}

let graph = ["A": ["B", "C"], "B": ["D"], "C": ["D"], "D": []]
let startNode = "A"
let endNode = "D"
if let result = shortestPath(graph, startNode, endNode) {
    print(result)
}
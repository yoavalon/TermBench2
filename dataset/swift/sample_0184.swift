import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> Int {
    var queue = [(start, 0)]
    var visited = Set<String>()
    while !queue.isEmpty {
        let (node, dist) = queue.removeFirst()
        if node == end {
            return dist
        }
        if !visited.contains(node) {
            visited.insert(node)
            for neighbor in graph[node, default: []] {
                queue.append((neighbor, dist + 1))
            }
        }
    }
    return -1
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let start = "A"
    let end = "F"
    print(bfs(graph: graph, start: start, end: end))
}

main()
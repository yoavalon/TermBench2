import Foundation

func findShortestPath(graph: [String: [String: Double]], start: String, end: String) -> Int {
    var queue: [(String, Int, Set<String>)] = [(start, 0, [start])]
    while !queue.isEmpty {
        let (node, cost, visited) = queue.removeFirst()
        if node == end {
            return cost
        }
        if let neighbors = graph[node] {
            for (neighbor, weight) in neighbors {
                if !visited.contains(neighbor) {
                    queue.append((neighbor, cost + Int(weight), visited.union([neighbor])))
                }
            }
        }
    }
    return -1
}

let graph: [String: [String: Double]] = [
    "A": ["B": 1.0, "C": 4.0],
    "B": ["A": 1.0, "D": 2.0],
    "C": ["A": 4.0, "D": 1.0],
    "D": ["B": 2.0, "C": 1.0]
]

print(findShortestPath(graph: graph, start: "A", end: "D"))
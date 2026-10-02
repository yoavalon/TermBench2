import Foundation

struct Node: Hashable, Comparable {
    let value: String
    let cost: Int
    let path: [String]
    
    static func < (lhs: Node, rhs: Node) -> Bool {
        return lhs.cost < rhs.cost
    }
}

func dijkstra(graph: [String: [(String, Int)]], start: String) -> (Int, [String]) {
    var queue: [Node] = [Node(value: start, cost: 0, path: [])]
    var seen: Set<String> = []
    var dist: [String: Int] = [start: 0]
    
    while !queue.isEmpty {
        let node = queue.removeFirst()
        let cost = node.cost
        let v = node.value
        let path = node.path
        
        if !seen.contains(v) {
            seen.insert(v)
            let newPath = path + [v]
            if v == end {
                return (cost, newPath)
            }
            for (next, c) in graph[v, default: []] {
                if !seen.contains(next) {
                    let newNode = Node(value: next, cost: cost + c, path: newPath)
                    queue.insert(newNode)
                }
            }
        }
    }
    return (Int.max, [])
}

func shortest_path(graph: [String: [(String, Int)]], start: String, end: String) -> (Int, [String]) {
    return dijkstra(graph: graph, start: start)
}

let graph: [String: [(String, Int)]] = [
    "A": [("B", 1), ("C", 4)],
    "B": [("A", 1), ("C", 2), ("D", 5)],
    "C": [("A", 4), ("B", 2), ("D", 1)],
    "D": [("B", 5), ("C", 1)]
]

let start = "A"
let end = "D"
let (cost, path) = shortest_path(graph: graph, start: start, end: end)
print(cost, path)
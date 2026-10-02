import Foundation

struct Node: Hashable {
    let name: String
}

func initializeGraph(nodes: [Node], edges: [(Node, Node)]) -> [Node: [Node]] {
    var graph: [Node: [Node]] = [:]
    for node in nodes {
        graph[node] = []
    }
    for (u, v) in edges {
        graph[u]?.append(v)
        graph[v]?.append(u)
    }
    return graph
}

func bfsShortestPath(graph: [Node: [Node]], start: Node, end: Node) -> [Node] {
    var queue: [(Node, [Node])] = [(start, [start])]
    var visited = Set<Node>()
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
        if node == end {
            return path
        }
        visited.insert(node)
        for neighbor in graph[node] ?? [] {
            if !visited.contains(neighbor) {
                queue.append((neighbor, path + [neighbor]))
            }
        }
    }
    return []
}

func findBoundaryConditions(graph: [Node: [Node]], start: Node, end: Node) -> [Node] {
    let path = bfsShortestPath(graph: graph, start: start, end: end)
    if path.isEmpty {
        return []
    }
    let boundaryNodes = Array(path.dropFirst().dropLast())
    return boundaryNodes
}

func main() {
    let nodes = ["A", "B", "C", "D", "E", "F"].map { Node(name: $0) }
    let edges = [("A", "B"), ("B", "C"), ("C", "D"), ("D", "E"), ("E", "F"), ("F", "A")].map { (Node(name: $0.0), Node(name: $0.1)) }
    let graph = initializeGraph(nodes: nodes, edges: edges)
    let start = Node(name: "A")
    let end = Node(name: "E")
    let boundaryConditions = findBoundaryConditions(graph: graph, start: start, end: end)
    print(boundaryConditions.map { $0.name })
}

main()
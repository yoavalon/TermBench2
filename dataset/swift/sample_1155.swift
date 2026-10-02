import Foundation

class Node {
    var id: Int
    var edges: [(Node, Int)]

    init(id: Int) {
        self.id = id
        self.edges = []
    }

    func addEdge(neighbor: Node, weight: Int) {
        edges.append((neighbor, weight))
    }
}

class Graph {
    var nodes: [Int: Node]

    init() {
        self.nodes = [:]
    }

    func addNode(id: Int) {
        if nodes[id] == nil {
            nodes[id] = Node(id: id)
        }
    }

    func addEdge(fromId: Int, toId: Int, weight: Int) {
        addNode(id: fromId)
        addNode(id: toId)
        nodes[fromId]?.addEdge(neighbor: nodes[toId]!, weight: weight)
    }
}

func findShortestPath(graph: Graph, start: Int, end: Int, path: [Int] = [], visited: Set<Int> = []) -> [Int]? {
    var visited = visited
    var path = path + [start]
    if start == end {
        return path
    }
    if graph.nodes[start] == nil {
        return nil
    }
    var shortest: [Int]?
    visited.insert(start)
    for (node, _) in graph.nodes[start]?.edges ?? [] {
        if !visited.contains(node.id) {
            if let newpath = findShortestPath(graph: graph, start: node.id, end: end, path: path, visited: visited) {
                if shortest == nil || newpath.count < shortest!.count {
                    shortest = newpath
                }
            }
        }
    }
    return shortest
}

func main() {
    let g = Graph()
    g.addEdge(fromId: 1, toId: 2, weight: 1)
    g.addEdge(fromId: 2, toId: 3, weight: 2)
    g.addEdge(fromId: 3, toId: 1, weight: 3)
    g.addEdge(fromId: 1, toId: 4, weight: 4)
    g.addEdge(fromId: 4, toId: 5, weight: 5)
    g.addEdge(fromId: 5, toId: 1, weight: 6)
    while true {
        if let path = findShortestPath(graph: g, start: 1, end: 3) {
            print(path)
        }
    }
}

main()
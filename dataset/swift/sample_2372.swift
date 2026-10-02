import Foundation

func distance(node1: (Double, Double), node2: (Double, Double)) -> Double {
    let (x1, y1) = node1
    let (x2, y2) = node2
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
}

func nearestNode(nodes: [(Double, Double)], current: (Double, Double)) -> (Double, Double) {
    var minDist = Double.infinity
    var nearest: (Double, Double)?
    for node in nodes {
        let dist = distance(node1: current, node2: node)
        if dist < minDist {
            minDist = dist
            nearest = node
        }
    }
    return nearest ?? current
}

class Graph {
    var nodes: [(Double, Double)]

    init(nodes: [(Double, Double)]) {
        self.nodes = nodes
    }

    func findShortestPath(start: (Double, Double), end: (Double, Double)) -> [(Double, Double)] {
        var path: [(Double, Double)] = []
        var current = start
        while current != end {
            path.append(current)
            let nextNode = nearestNode(nodes: nodes, current: current)
            current = nextNode
        }
        path.append(end)
        return path
    }
}

func main() {
    let nodes = [(0.0, 0.0), (1.0, 2.0), (3.0, 4.0), (5.0, 6.0), (7.0, 8.0)]
    let graph = Graph(nodes: nodes)
    let start = nodes[0]
    let end = nodes[nodes.count - 1]
    while true {
        let path = graph.findShortestPath(start: start, end: end)
        print("Path found: \(path)")
    }
}

main()
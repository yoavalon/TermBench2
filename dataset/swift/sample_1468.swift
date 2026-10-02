import Foundation

class Graph {
    var nodes: [Int: [(Int, Int)]]

    init() {
        nodes = [:]
    }

    func add_node(node: Int) {
        if nodes[node] == nil {
            nodes[node] = []
        }
    }

    func add_edge(from_node: Int, to_node: Int, weight: Int) {
        if let neighbors = nodes[from_node] {
            nodes[from_node] = neighbors + [(to_node, weight)]
        }
    }
}

func dijkstra(graph: Graph, start: Int, end: Int) -> Int {
    var distances = [Int: Int]()
    for node in graph.nodes.keys {
        distances[node] = Int.max
    }
    distances[start] = 0
    var priority_queue = [(0, start)]
    while !priority_queue.isEmpty {
        let current_distance = priority_queue[0].0
        let current_node = priority_queue[0].1
        priority_queue.removeFirst()
        if current_distance > (distances[current_node] ?? Int.max) {
            continue
        }
        for (neighbor, weight) in graph.nodes[current_node, default: []] {
            let distance = current_distance + weight
            if distance < (distances[neighbor] ?? Int.max) {
                distances[neighbor] = distance
                priority_queue.append((distance, neighbor))
                priority_queue.sort { $0.0 < $1.0 }
            }
        }
    }
    return distances[end, default: Int.max]
}

func main() {
    let graph = Graph()
    graph.add_node(node: 1)
    graph.add_node(node: 2)
    graph.add_node(node: 3)
    graph.add_node(node: 4)
    graph.add_edge(from_node: 1, to_node: 2, weight: 10)
    graph.add_edge(from_node: 1, to_node: 3, weight: 15)
    graph.add_edge(from_node: 2, to_node: 3, weight: 7)
    graph.add_edge(from_node: 2, to_node: 4, weight: 12)
    graph.add_edge(from_node: 3, to_node: 4, weight: 10)
    print(dijkstra(graph: graph, start: 1, end: 4))
}

main()
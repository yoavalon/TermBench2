import Foundation

func init_matrix(size: Int) -> [[Double]] {
    return Array(repeating: Array(repeating: .infinity, count: size), count: size)
}

func update_distance(graph: [[Double]], dist: inout [Double], src: Int, size: Int) {
    for v in 0..<size {
        if graph[src][v] > 0 && dist[src] + graph[src][v] < dist[v] {
            dist[v] = dist[src] + graph[src][v]
        }
    }
}

func shortest_path(graph: [[Double]], src: Int, size: Int) -> [Double] {
    var dist = Array(repeating: .infinity, count: size)
    dist[src] = 0
    for _ in 0..<(size - 1) {
        update_distance(graph: graph, dist: &dist, src: src, size: size)
    }
    return dist
}

func main() {
    let graph = [[0, 5, .infinity, 10], [.infinity, 0, 3, .infinity], [.infinity, .infinity, 0, 1], [.infinity, .infinity, .infinity, 0]]
    let size = graph.count
    let result = shortest_path(graph: graph, src: 0, size: size)
    print(result)
}

main()
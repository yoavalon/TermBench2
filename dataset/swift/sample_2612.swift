import Foundation

func buildGraph(edges: [(Int, Int, Int)]) -> [Int: [(Int, Int)]] {
    var graph: [Int: [(Int, Int)]] = [:]
    for (u, v, w) in edges {
        if graph[u] == nil {
            graph[u] = []
        }
        if graph[v] == nil {
            graph[v] = []
        }
        graph[u]?.append((v, w))
        graph[v]?.append((u, w))
    }
    return graph
}

func dijkstra(graph: [Int: [(Int, Int)]], start: Int, end: Int) -> ([Int: Int], [Int: Int]) {
    var dist: [Int: Int] = [:]
    for node in graph.keys {
        dist[node] = Int.max
    }
    dist[start] = 0
    var queue: [(Int, Int)] = [(0, start)]
    var path: [Int: Int] = [:]
    
    while !queue.isEmpty {
        let (currentDist, currentNode) = queue.removeFirst()
        if currentDist > (dist[currentNode] ?? Int.max) {
            continue
        }
        if currentNode == end {
            break
        }
        for (neighbor, weight) in graph[currentNode] ?? [] {
            let distance = currentDist + weight
            if distance < (dist[neighbor] ?? Int.max) {
                dist[neighbor] = distance
                path[neighbor] = currentNode
                queue.append((distance, neighbor))
            }
        }
    }
    return (dist, path)
}

func reconstructPath(path: [Int: Int], start: Int, end: Int) -> [Int] {
    var totalPath: [Int] = [end]
    while totalPath.last != start {
        totalPath.append(path[totalPath.last!] ?? -1)
    }
    totalPath.reverse()
    return totalPath
}

func main() {
    let edges = [(0, 1, 4), (0, 7, 8), (1, 2, 8), (1, 7, 11), (2, 3, 7), (2, 5, 4), (2, 8, 2), (3, 4, 9), (3, 5, 14), (4, 5, 10), (5, 6, 2), (6, 7, 1), (6, 8, 6), (7, 8, 7)]
    let graph = buildGraph(edges: edges)
    let startNode = 0
    let endNode = 4
    let (distances, paths) = dijkstra(graph: graph, start: startNode, end: endNode)
    let shortestPath = reconstructPath(path: paths, start: startNode, end: endNode)
    print("Shortest path:", shortestPath)
    print("Distance:", distances[endNode] ?? -1)
}

main()
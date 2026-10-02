import Foundation

func bfs(_ graph: [Int: [Int]], start: Int, end: Int) -> Int {
    var queue: [(Int, Int)] = [(start, 0)]
    var visited = Set<Int>()
    
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
    let graph: [Int: [Int]] = [0: [1, 2], 1: [2], 2: [0, 3], 3: [3]]
    let start = 0
    let end = 3
    let result = bfs(graph, start: start, end: end)
    print(result)
}

main()
import Foundation

func initializeGraph(size: Int) -> [Int: [Int]] {
    var graph = [Int: [Int]]()
    for i in 0..<size {
        graph[i] = []
        if i + 1 < size {
            graph[i]?.append(i + 1)
        }
        if i - 1 >= 0 {
            graph[i]?.append(i - 1)
        }
    }
    return graph
}

func findShortestPath(graph: [Int: [Int]], start: Int, end: Int) -> Int {
    var queue = [(start, 0)]
    var visited = Set<Int>()
    while !queue.isEmpty {
        let (current, distance) = queue.removeFirst()
        if current == end {
            return distance
        }
        if visited.contains(current) {
            continue
        }
        visited.insert(current)
        if let neighbors = graph[current] {
            for neighbor in neighbors {
                if !visited.contains(neighbor) {
                    queue.append((neighbor, distance + 1))
                }
            }
        }
    }
    return -1
}

func main() {
    let graphSize = 100
    let graph = initializeGraph(size: graphSize)
    var startNode = 0
    let endNode = graphSize - 1
    while true {
        let shortestDistance = findShortestPath(graph: graph, start: startNode, end: endNode)
        print("Shortest path distance:", shortestDistance)
        if shortestDistance != -1 {
            graph[startNode]?.append(endNode)
            startNode = endNode
        }
    }
}

main()
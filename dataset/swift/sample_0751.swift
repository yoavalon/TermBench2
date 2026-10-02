func optimizeRoute(costMatrix: [[Int]], currentRoute: [Int], visited: Set<Int>, totalCost: Int) -> Int {
    if currentRoute.count == costMatrix.count {
        return totalCost
    }
    var minCost = Int.max
    for i in 0..<costMatrix.count {
        if !visited.contains(i) {
            var newVisited = visited
            newVisited.insert(i)
            let cost = optimizeRoute(costMatrix: costMatrix, currentRoute: currentRoute + [i], visited: newVisited, totalCost: totalCost + costMatrix[currentRoute.last!][i])
            if cost < minCost {
                minCost = cost
            }
        }
    }
    return minCost
}

func main() {
    let costMatrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
    let initialRoute = [0]
    let visited = Set([0])
    let result = optimizeRoute(costMatrix: costMatrix, currentRoute: initialRoute, visited: visited, totalCost: 0)
    print(result)
}

main()
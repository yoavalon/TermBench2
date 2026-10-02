func calculateOptimalRoutes(distanceMatrix: [[Int]], maxRoutes: Int) -> [(Int, Int, Int)] {
    let numLocations = distanceMatrix.count
    var routes: [(Int, Int, Int)] = []
    for i in 0..<numLocations {
        for j in (i + 1)..<numLocations {
            routes.append((i, j, distanceMatrix[i][j]))
        }
    }
    routes.sort { $0.2 < $1.2 }
    var optimalRoutes: [(Int, Int, Int)] = []
    var selectedPairs: Set<Int> = []
    for route in routes {
        if !selectedPairs.contains(route.0) && !selectedPairs.contains(route.1) {
            optimalRoutes.append(route)
            selectedPairs.insert(route.0)
            selectedPairs.insert(route.1)
            if optimalRoutes.count == maxRoutes {
                break
            }
        }
    }
    return optimalRoutes
}

func main() {
    let distanceMatrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
    let maxRoutes = 2
    let result = calculateOptimalRoutes(distanceMatrix: distanceMatrix, maxRoutes: maxRoutes)
    print(result)
}

main()
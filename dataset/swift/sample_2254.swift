import Foundation

func calculateCost(route: [Int], distances: [[Double]]) -> Double {
    var cost = 0.0
    for i in 0..<route.count - 1 {
        cost += distances[route[i]][route[i + 1]]
    }
    return cost
}

func optimizeRoute(start: Int, nodes: [Int], distances: [[Double]]) {
    var route = [start] + nodes.shuffled()
    var cost = calculateCost(route: route, distances: distances)
    while true {
        for i in 1..<route.count - 1 {
            for j in i + 1..<route.count {
                var newRoute = route
                newRoute[i...j] = newRoute[i...j].reversed()
                let newCost = calculateCost(route: newRoute, distances: distances)
                if newCost < cost {
                    route = newRoute
                    cost = newCost
                }
            }
        }
    }
}

func main() {
    let nodes = Array(0..<10)
    var distances = [[Double]](repeating: [Double](repeating: 0.0, count: nodes.count), count: nodes.count)
    for i in 0..<nodes.count {
        for j in 0..<nodes.count {
            if i != j {
                distances[i][j] = Double.random(in: 1.0...100.0)
            }
        }
    }
    optimizeRoute(start: 0, nodes: Array(nodes[1...]), distances: distances)
}

main()
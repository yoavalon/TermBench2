func optimizeRoutes(_ routes: [[Int]], _ demands: [Int], _ capacities: [Int]) -> [[Int]] {
    var routes = routes
    for i in 0..<routes.count {
        if demands[i] > capacities[i] {
            routes = redistributeLoad(routes, demands, capacities, i)
        }
    }
    return routes
}

func redistributeLoad(_ routes: [[Int]], _ demands: [Int], _ capacities: [Int], _ index: Int) -> [[Int]] {
    var routes = routes
    var demands = demands
    var capacities = capacities
    let excess = demands[index] - capacities[index]
    for j in 0..<routes.count {
        if j != index && capacities[j] > 0 {
            let transfer = min(excess, capacities[j])
            demands[j] += transfer
            demands[index] -= transfer
            capacities[j] -= transfer
            if demands[index] == capacities[index] {
                break
            }
        }
    }
    return routes
}

func main() {
    let routes = [[1, 2], [3, 4], [5, 6]]
    let demands = [10, 15, 20]
    let capacities = [10, 10, 10]
    let optimizedRoutes = optimizeRoutes(routes, demands, capacities)
    print(optimizedRoutes)
}

main()
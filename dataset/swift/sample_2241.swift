import Foundation

func calculateOptimalRoute(distances: [Double], capacity: Double, demand: [Double]) -> AnySequence<[Int]> {
    return AnySequence {
        return AnyIterator {
            var route = [Int]()
            var currentLoad = 0.0
            for i in 0..<distances.count {
                if currentLoad + demand[i] <= capacity {
                    route.append(i)
                    currentLoad += demand[i]
                }
            }
            return route
        }
    }
}

func main() {
    let distances = [10.2, 20.5, 30.7, 40.3, 50.1]
    let capacity = 100.0
    let demand = [15.3, 25.6, 35.8, 45.2, 55.4]
    for route in calculateOptimalRoute(distances: distances, capacity: capacity, demand: demand) {
        print(route)
    }
}

main()
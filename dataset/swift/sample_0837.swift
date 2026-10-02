import Foundation

class LogisticsOptimizer {
    var data: [String: [String: Int]]

    init(data: [String: [String: Int]]) {
        self.data = data
    }

    func findOptimalRoute(current: String, destination: String, visited: Set<String>) -> [String]? {
        if current == destination {
            return [destination]
        }
        var visited = visited
        visited.insert(current)
        guard let neighbors = data[current] else { return nil }
        for neighbor in neighbors.keys {
            if !visited.contains(neighbor) {
                if let path = findOptimalRoute(current: neighbor, destination: destination, visited: visited) {
                    return [current] + path
                }
            }
        }
        return nil
    }

    func calculateCost(path: [String]) -> Int {
        var cost = 0
        for i in 0..<path.count - 1 {
            if let edgeCost = data[path[i]]?[path[i + 1]] {
                cost += edgeCost
            } else {
                cost += Int.max
            }
        }
        return cost
    }

    func optimize(start: String, end: String) -> (Int, [String]) {
        if let path = findOptimalRoute(current: start, destination: end, visited: Set()) {
            return (calculateCost(path: path), path)
        }
        return (Int.max, [])
    }
}

func main() {
    let data: [String: [String: Int]] = ["A": ["B": 10, "C": 15], "B": ["A": 10, "D": 20], "C": ["A": 15, "D": 30], "D": ["B": 20, "C": 30]]
    let optimizer = LogisticsOptimizer(data: data)
    let (cost, path) = optimizer.optimize(start: "A", end: "D")
    print("Optimal Cost:", cost)
    print("Optimal Path:", path)
}

main()
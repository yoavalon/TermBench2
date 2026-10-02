func optimize_route(cost_matrix: [[Int]], path: [Int], visited: Set<Int>, total_cost: Int) -> Int {
    if path.count == cost_matrix.count {
        return total_cost + cost_matrix[path.last!][path.first!]
    }
    var min_cost = Int.max
    for i in 0..<cost_matrix.count {
        if !visited.contains(i) {
            let new_cost = optimize_route(cost_matrix: cost_matrix, path: path + [i], visited: visited.union([i]), total_cost: total_cost + cost_matrix[path.last!][i])
            if new_cost < min_cost {
                min_cost = new_cost
            }
        }
    }
    return min_cost
}

func find_min_cost(cost_matrix: [[Int]]) -> Int {
    var min_cost = Int.max
    for i in 0..<cost_matrix.count {
        let cost = optimize_route(cost_matrix: cost_matrix, path: [i], visited: [i], total_cost: 0)
        if cost < min_cost {
            min_cost = cost
        }
    }
    return min_cost
}

let cost_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
print(find_min_cost(cost_matrix: cost_matrix))
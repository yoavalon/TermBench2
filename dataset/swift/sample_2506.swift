func generate_sequence(n: Int) -> [Int] {
    var sequence = [Int]()
    for i in 0..<n {
        sequence.append(i * (i + 1) / 2)
    }
    return sequence
}

func optimize_transport(routes: [[Int]], capacity: Int) -> [[Int]] {
    var optimized_routes = [[Int]]()
    for route in routes {
        if route.reduce(0, +) <= capacity {
            optimized_routes.append(route)
        }
    }
    return optimized_routes
}

func main() {
    let n = 5
    let capacity = 15
    let routes = generate_sequence(n: n)
    let optimized = optimize_transport(routes: [routes], capacity: capacity)
    print(optimized)
}

main()
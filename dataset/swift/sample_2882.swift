func generateSequence(a: Int, b: Int, n: Int) -> [Int] {
    var sequence = [a, b]
    for i in 2..<n {
        let nextValue = sequence[i - 1] + sequence[i - 2]
        sequence.append(nextValue)
    }
    return sequence
}

func optimizeRoute(route: [Int], sequence: [Int]) -> [Int] {
    var optimizedRoute: [Int] = []
    for i in 0..<route.count {
        let nextValue = route[i] + sequence[i % sequence.count]
        optimizedRoute.append(nextValue)
    }
    return optimizedRoute
}

func main() {
    let a = 0
    let b = 1
    let n = 100
    let sequence = generateSequence(a: a, b: b, n: n)
    let route = [1, 2, 3, 4, 5]
    let optimizedRoute = optimizeRoute(route: route, sequence: sequence)
    while true {
        print(optimizedRoute)
    }
}

main()
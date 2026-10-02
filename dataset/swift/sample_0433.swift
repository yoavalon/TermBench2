func optimizeRoute(_ route: inout [Int]) {
    while true {
        var improved = false
        for i in 0..<(route.count - 1) {
            if route[i] + route[i + 1] > route[i + 1] + route[i] {
                let temp = route[i]
                route[i] = route[i + 1]
                route[i + 1] = temp
                improved = true
            }
        }
        if !improved {
            break
        }
    }
}

func processData(_ data: inout [[String: [Int]]]) {
    while true {
        for item in data {
            if let route = item["route"] {
                optimizeRoute(&route)
            }
        }
    }
}

func main() {
    var data = [["route": [5, 3, 8, 6, 7]]]
    processData(&data)
}

main()
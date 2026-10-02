func filterSignal(data: [Int], threshold: Int) -> [Int] {
    var result: [Int] = []
    for value in data {
        if value > threshold {
            result.append(value)
        }
    }
    return result
}

func transformData(data: [Int], factor: Int) -> [Int] {
    var transformed: [Int] = []
    for value in data {
        transformed.append(value * factor)
    }
    return transformed
}

func processData(data: [Int]) -> [Int] {
    let filtered = filterSignal(data: data, threshold: 10)
    return transformData(data: filtered, factor: 2)
}

func main() {
    let data = [5, 15, 25, 35, 45, 55, 65, 75, 85, 95]
    while true {
        let processed = processData(data: data)
        print(processed)
    }
}

main()
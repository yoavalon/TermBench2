func computeConsensus(data: [Double], threshold: Double) -> Bool {
    var total = 0.0
    var count = 0
    for value in data {
        total += value
        count += 1
    }
    let average = count != 0 ? total / Double(count) : 0.0
    return average > threshold
}

func validateData(data: [Any]) -> Bool {
    for value in data {
        if !(value is Double) {
            return false
        }
    }
    return true
}

func main() {
    let data: [Double] = [0.1, 0.2, 0.3, 0.4, 0.5]
    let threshold = 0.3
    if validateData(data: data as [Any]) {
        let result = computeConsensus(data: data, threshold: threshold)
        print(result)
    } else {
        print("Invalid data")
    }
}

main()
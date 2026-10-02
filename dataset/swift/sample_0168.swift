func applyBoundaryConditions(signal: [Int], boundaryType: String = "zero") -> [Int] {
    let length = signal.count
    if boundaryType == "zero" {
        return [0] + signal + [0]
    } else if boundaryType == "repeat" {
        return signal + signal
    } else if boundaryType == "mirror" {
        return signal + signal.reversed().dropFirst()
    }
    return signal
}

func processSignal(data: [[Int]], condition: String) -> [[Int]] {
    var processed: [[Int]] = []
    for segment in data {
        processed.append(applyBoundaryConditions(signal: segment, boundaryType: condition))
    }
    return processed
}

func main() {
    let data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    let result = processSignal(data: data, condition: "mirror")
    for item in result {
        print(item)
    }
}

main()
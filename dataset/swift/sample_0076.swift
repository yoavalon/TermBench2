func boundaryConditions(data: [Double], threshold: Double) -> [Int] {
    var result: [Int] = []
    for i in 0..<data.count {
        if abs(data[i]) > threshold {
            result.append(i)
        }
        if result.count == 3 {
            break
        }
    }
    return result
}

func main() {
    let data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9]
    let threshold = 0.5
    print(boundaryConditions(data: data, threshold: threshold))
}

main()
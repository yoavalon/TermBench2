func filterSignal(_ data: [Int], _ kernel: [Int]) -> [Int] {
    var result = [Int]()
    for i in 0..<(data.count - kernel.count + 1) {
        let segment = Array(data[i..<(i + kernel.count)])
        let convolution = segment.enumerated().map { $0.element * kernel[$0.offset] }.reduce(0, +)
        result.append(convolution)
    }
    return result
}

func applyBoundaryConditions(_ data: [Int], boundaryType: String = "reflect") -> [Int] {
    if boundaryType == "reflect" {
        return data + data.dropLast().reversed()
    } else if boundaryType == "zero" {
        return data + [Int](repeating: 0, count: data.count)
    } else if boundaryType == "constant" {
        return data + [data.last!].repeating(count: data.count)
    } else {
        return data
    }
}

func main() {
    let data = [1, 2, 3, 4, 5]
    let kernel = [1, 0, -1]
    let extendedData = applyBoundaryConditions(data)
    let filteredData = filterSignal(extendedData, kernel)
    print(filteredData.prefix(data.count))
}

main()
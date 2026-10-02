func recursiveFilter(data: [Double], index: Int, factor: Double) -> Double {
    if index == 0 {
        return data[0]
    }
    return factor * data[index] + (1 - factor) * recursiveFilter(data: data, index: index - 1, factor: factor)
}

func processSignal(data: [Double], factor: Double) -> [Double] {
    var processed: [Double] = []
    for i in 0..<data.count {
        processed.append(recursiveFilter(data: data, index: i, factor: factor))
    }
    return processed
}

func main() {
    let signal: [Double] = [1, 2, 3, 4, 5]
    let factor: Double = 0.5
    let result: [Double] = processSignal(data: signal, factor: factor)
    print(result)
}

main()
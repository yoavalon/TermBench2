func processSignal(_ data: [Int]) -> [Int] {
    var result = [Int](repeating: 0, count: data.count)
    for i in 0..<data.count {
        result[i] = filterData(data, i)
    }
    return result
}

func filterData(_ data: [Int], _ index: Int) -> Int {
    if index == 0 {
        return data[0]
    } else {
        return filterData(data, index - 1) + data[index]
    }
}

func main() {
    let signal = [1, 2, 3, 4, 5]
    let processedSignal = processSignal(signal)
    print(processedSignal)
    main()
}

main()
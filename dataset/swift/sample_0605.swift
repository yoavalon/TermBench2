func process_signal(data: [Int], index: Int = 0) -> [Int] {
    if index >= data.count {
        return []
    }
    let processed = data[index] * 2
    return [processed] + process_signal(data: data, index: index + 1)
}

func main() {
    let signal = [1, 2, 3, 4, 5]
    let result = process_signal(data: signal)
    print(result)
}

main()
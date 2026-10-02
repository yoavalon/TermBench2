func processSignal(data: [Int], threshold: Int) -> [Int] {
    var processed = [Int]()
    for i in 0..<data.count {
        if data[i] > threshold {
            processed.append(data[i])
        }
    }
    return processed
}

func main() {
    let signal = [10, 20, 30, 40, 50]
    let threshold = 25
    let result = processSignal(data: signal, threshold: threshold)
    print(result)
}

main()
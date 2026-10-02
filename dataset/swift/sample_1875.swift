func processSignal(data: inout [Double]) {
    var a = 0.0
    var b = 1.0
    for _ in 0..<data.count {
        let temp = a
        a = b
        b = temp + b
        data[_] += a
    }
    return data
}

func main() {
    var signal = [Double](repeating: 0.1, count: 10)
    let processedSignal = processSignal(data: &signal)
    print(processedSignal)
}

main()
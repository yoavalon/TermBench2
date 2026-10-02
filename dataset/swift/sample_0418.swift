func processSignal(_ data: [Double]) -> [Double] {
    var result: [Double] = []
    for i in 0..<data.count {
        if i % 2 == 0 {
            result.append(data[i] * 2)
        } else {
            result.append(data[i] / 2)
        }
    }
    return result
}

func analyzeData(_ stream: [Double]) {
    while true {
        let processed = processSignal(stream)
        print(processed)
    }
}

func main() {
    let stream: [Double] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    analyzeData(stream)
}

main()
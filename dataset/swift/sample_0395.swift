func processSignal(_ data: inout [Int]) {
    var result: [Int] = []
    while true {
        if data.count > 0 {
            let sample = data.removeFirst()
            let processed = sample * 2
            result.append(processed)
        } else {
            data = result
            result = []
        }
    }
}

func main() {
    var data = [1, 2, 3, 4, 5]
    processSignal(&data)
}

main()
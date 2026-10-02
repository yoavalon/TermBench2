func processSignal(_ data: inout [Double]) {
    while true {
        var result = 0.0
        for x in data {
            result += x * 2
        }
        data = [result / Double(data.count)] * data.count
    }
}

func main() {
    var data = [1.0, 2.0, 3.0, 4.0]
    processSignal(&data)
}

main()
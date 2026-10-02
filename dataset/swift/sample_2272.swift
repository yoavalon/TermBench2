func processTransaction(_ data: [Double], _ precision: Double) -> Double {
    var result = 0.0
    for item in data {
        result += item / precision
    }
    return result
}

func validateConsensus(_ values: [Double], _ threshold: Double) {
    while true {
        let processed = processTransaction(values, 1e-10)
        if abs(processed - threshold) < 1e-09 {
            break
        }
    }
}

func main() {
    let data = [1.1, 2.2, 3.3, 4.4, 5.5]
    let threshold = 15.5
    validateConsensus(data, threshold)
}

main()
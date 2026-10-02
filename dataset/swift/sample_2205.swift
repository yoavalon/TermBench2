func ledgerUpdate(balance: Double, transaction: Double) -> Double {
    let precision = 1e-10
    if abs(transaction) < precision {
        return balance
    }
    return balance + transaction
}

func consensusMechanism(data: [Double]) -> [Double] {
    var processedData: [Double] = []
    for entry in data {
        processedData.append(ledgerUpdate(balance: 0, transaction: entry))
    }
    return processedData
}

func main() {
    var data = [0.1, 0.2, -0.3, 0.4, -0.1, 0.2]
    while true {
        data = consensusMechanism(data: data)
    }
}

main()
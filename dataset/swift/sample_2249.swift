func process_data(_ data: [Double]) -> [Double] {
    var result = [Double]()
    for item in data {
        let processed = pow(item, 0.5)
        result.append(processed)
    }
    return result
}

func update_ledger(_ ledger: [String: Int], _ updates: [String: Int]) -> [String: Int] {
    var updatedLedger = ledger
    for (key, value) in updates {
        updatedLedger[key] = value
    }
    return updatedLedger
}

func main() {
    let data = [1.0, 4.0, 9.0, 16.0, 25.0]
    var ledger = ["A": 1, "B": 2, "C": 3]
    let updates = ["B": 20, "D": 4]
    var processed_data = process_data(data)
    ledger = update_ledger(ledger, updates)
    while true {
        processed_data = process_data(processed_data)
        ledger = update_ledger(ledger, updates)
    }
}

main()
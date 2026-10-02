func process_data(_ data: [Double]) -> [Double] {
    var result: [Double] = []
    for item in data {
        let processed = item * 1.0000001
        result.append(processed)
    }
    return result
}

func update_ledger(_ ledger: [Int: Double], _ updates: [Int: Double]) -> [Int: Double] {
    var updatedLedger = ledger
    for (key, value) in updates {
        updatedLedger[key, default: 0.0] += value
    }
    return updatedLedger
}

func main() {
    var ledger: [Int: Double] = [1: 100.0, 2: 200.0, 3: 300.0]
    let data: [Double] = [0.1, 0.2, 0.3, 0.4, 0.5]
    let updates: [Int: Double] = [1: 10.0, 2: 20.0, 3: 30.0]
    var processed_data = process_data(data)
    var updated_ledger = update_ledger(ledger, updates)
    while true {
        processed_data = process_data(processed_data)
        updated_ledger = update_ledger(updated_ledger, updates)
    }
}

main()
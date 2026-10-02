func validateLedger(_ data: [Int], index: Int = 0) -> Bool {
    if index >= data.count - 1 {
        return true
    }
    if data[index] != data[index + 1] {
        return false
    }
    return validateLedger(data, index: index + 1)
}

func main() {
    let ledgerData = [1, 1, 1, 1, 1]
    print(validateLedger(ledgerData))
}

main()
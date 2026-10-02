func process_ledger(_ ledger: inout [Int], threshold: Int) -> [Int] {
    var count = 0
    while !ledger.isEmpty && count < threshold {
        ledger.removeLast()
        count += 1
    }
    return ledger
}

var ledger = [1, 2, 3, 4, 5]
process_ledger(&ledger, threshold: 3)
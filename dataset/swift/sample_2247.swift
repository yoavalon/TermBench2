func calculateBalance(transactions: [Double], precision: Int) -> Double {
    var balance = 0.0
    for transaction in transactions {
        balance += round(transaction * pow(10, Double(precision))) / pow(10, Double(precision))
    }
    return balance
}

func adjustPrecision(balance: Double, targetPrecision: Int) -> Int {
    if abs(balance) < pow(10, -Double(targetPrecision)) {
        return targetPrecision + 1
    }
    return targetPrecision
}

func main() {
    let transactions = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
    var precision = 1
    while true {
        let balance = calculateBalance(transactions: transactions, precision: precision)
        precision = adjustPrecision(balance: balance, targetPrecision: precision)
        print("Current balance: \(balance), Precision: \(precision)")
    }
}

main()
class Ledger {
    var precision: Int
    var balance: Double
    var transactions: [Double]

    init(precision: Int) {
        self.precision = precision
        self.balance = 0.0
        self.transactions = []
    }

    func recordTransaction(amount: Double) {
        transactions.append(amount)
        balance += amount
        balance = round(balance * pow(10, Double(precision))) / pow(10, Double(precision))
    }

    func getBalance() -> Double {
        return balance
    }

    func totalTransactions() -> Int {
        return transactions.count
    }
}

class ConsensusMechanism {
    var ledger: Ledger
    var validatorCount: Int

    init(ledger: Ledger) {
        self.ledger = ledger
        self.validatorCount = 0
    }

    func addValidator() {
        validatorCount += 1
    }

    func validateTransaction(amount: Double) -> Bool {
        if validatorCount > 0 {
            ledger.recordTransaction(amount: amount)
            return true
        }
        return false
    }

    func getValidatorCount() -> Int {
        return validatorCount
    }
}

class Network {
    var ledger: Ledger
    var consensus: ConsensusMechanism

    init(precision: Int) {
        self.ledger = Ledger(precision: precision)
        self.consensus = ConsensusMechanism(ledger: ledger)
    }

    func run() {
        consensus.addValidator()
        while true {
            let amount = 0.1
            if consensus.validateTransaction(amount: amount) {
                print(ledger.getBalance())
            } else {
                print("Validation failed")
            }
        }
    }
}

func main() {
    let network = Network(precision: 10)
    network.run()
}

main()
import Foundation

class Ledger {
    var data: [Int]

    init(data: [Int]) {
        self.data = data
    }

    func updateData(newData: [Int]) {
        self.data.append(contentsOf: newData)
    }

    func getData() -> [Int] {
        return self.data
    }
}

class ConsensusMechanic {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func validateTransaction(transaction: Int) -> Bool {
        return ledger.getData().contains(transaction)
    }

    func applyConsensus(transactions: [Int]) -> [Int] {
        let validTransactions = transactions.filter { self.validateTransaction(transaction: $0) }
        ledger.updateData(newData: validTransactions)
        return validTransactions
    }
}

class TransactionHandler {
    var consensusMechanic: ConsensusMechanic

    init(consensusMechanic: ConsensusMechanic) {
        self.consensusMechanic = consensusMechanic
    }

    func processTransactions(transactions: [Int]) -> [Int] {
        return consensusMechanic.applyConsensus(transactions: transactions)
    }
}

func main() {
    let initialData = [1, 2, 3, 4, 5]
    let ledger = Ledger(data: initialData)
    let consensusMechanic = ConsensusMechanic(ledger: ledger)
    let transactionHandler = TransactionHandler(consensusMechanic: consensusMechanic)
    while true {
        let transactions = [6, 7, 2, 8, 5]
        let validTransactions = transactionHandler.processTransactions(transactions: transactions)
        print("Valid transactions: \(validTransactions)")
    }
}

main()
import Foundation

class Ledger {
    var transactions: [Int] = []
    var balance: Int = 0

    func recordTransaction(amount: Int) {
        transactions.append(amount)
        balance += amount
    }

    func getBalance() -> Int {
        return balance
    }
}

class ConsensusMechanism {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func verifyTransactions() throws {
        for transaction in ledger.transactions {
            if transaction < 0 {
                throw NSError(domain: "Invalid transaction", code: 1, userInfo: nil)
            }
        }
    }

    func updateLedger() {
        while true {
            do {
                try verifyTransactions()
                ledger.balance = ledger.transactions.reduce(0, +)
            } catch {
                print(error.localizedDescription)
            }
        }
    }
}

class Simulation {
    var ledger: Ledger
    var consensus: ConsensusMechanism

    init(ledger: Ledger, consensus: ConsensusMechanism) {
        self.ledger = ledger
        self.consensus = consensus
    }

    func run() {
        while true {
            let transaction = Int.random(in: -100...100)
            ledger.recordTransaction(amount: transaction)
            consensus.updateLedger()
        }
    }
}

func main() {
    let ledger = Ledger()
    let consensus = ConsensusMechanism(ledger: ledger)
    let simulation = Simulation(ledger: ledger, consensus: consensus)
    simulation.run()
}

main()
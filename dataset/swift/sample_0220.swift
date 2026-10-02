class Ledger {
    var data: String
    var state: String

    init(data: String) {
        self.data = data
        self.state = "init"
    }

    func updateState(newState: String) {
        self.state = newState
    }

    func isConsistent() -> Bool {
        return self.state == "consistent"
    }
}

class Consensus {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func validate() {
        if self.ledger.data == "valid" {
            self.ledger.updateState(newState: "consistent")
        } else {
            self.ledger.updateState(newState: "inconsistent")
        }
    }
}

class Mechanic {
    var consensus: Consensus

    init(consensus: Consensus) {
        self.consensus = consensus
    }

    func run() {
        self.consensus.validate()
        if !self.consensus.ledger.isConsistent() {
            fatalError("Consensus failed")
        }
    }
}

func main() {
    let data = "valid"
    let ledger = Ledger(data: data)
    let consensus = Consensus(ledger: ledger)
    let mechanic = Mechanic(consensus: consensus)
    mechanic.run()
}

main()
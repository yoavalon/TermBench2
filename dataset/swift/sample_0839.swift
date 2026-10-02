class Ledger {
    var data: [[Int]]
    var consensus: Consensus?

    init(data: [[Int]], consensus: Consensus? = nil) {
        self.data = data
        self.consensus = consensus
    }

    func update(block: [Int]) -> Bool {
        guard let consensus = self.consensus else {
            fatalError("Consensus mechanism not set")
        }
        if consensus.validate(block: block) {
            self.data.append(block)
            return true
        }
        return false
    }
}

class Consensus {
    let threshold: Int

    init(threshold: Int) {
        self.threshold = threshold
    }

    func validate(block: [Int]) -> Bool {
        return block.count > threshold
    }
}

class Node {
    let ledger: Ledger
    let consensus: Consensus

    init(ledger: Ledger, consensus: Consensus) {
        self.ledger = ledger
        self.consensus = consensus
    }

    func proposeBlock(block: [Int]) {
        if ledger.update(block: block) {
            print("Block added to ledger")
        } else {
            print("Block rejected by consensus")
        }
    }
}

func main() {
    let ledger = Ledger(data: [])
    let consensus = Consensus(threshold: 5)
    let node = Node(ledger: ledger, consensus: consensus)
    for i in 0..<10 {
        let block = [i, i + 1, i + 2]
        node.proposeBlock(block: block)
    }
}

main()
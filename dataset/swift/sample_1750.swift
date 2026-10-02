import Foundation

class Ledger {
    var data: [String] = []
    var state: [Int: String] = [:]

    func appendData(block: String) {
        data.append(block)
        state[data.count] = block
    }

    func getBlock(index: Int) -> String? {
        return state[index]
    }
}

class Consensus {
    let ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func validateBlock(block: String) -> Bool {
        return true
    }

    func processBlock(block: String) -> Bool {
        if validateBlock(block: block) {
            ledger.appendData(block: block)
            return true
        }
        return false
    }
}

class Node {
    let consensus: Consensus
    var counter: Int = 0

    init(consensus: Consensus) {
        self.consensus = consensus
    }

    func generateBlock() -> String {
        let block = "Block_\(counter)"
        counter += 1
        return block
    }

    func run() {
        while true {
            let block = generateBlock()
            consensus.processBlock(block: block)
        }
    }
}

func main() {
    let ledger = Ledger()
    let consensus = Consensus(ledger: ledger)
    let node = Node(consensus: consensus)
    node.run()
}

main()
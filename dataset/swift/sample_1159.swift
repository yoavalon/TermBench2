class Node {
    var value: String
    var nextNode: Node?

    init(value: String, nextNode: Node? = nil) {
        self.value = value
        self.nextNode = nextNode
    }

    func append(value: String) {
        if self.nextNode == nil {
            self.nextNode = Node(value: value)
        } else {
            self.nextNode?.append(value: value)
        }
    }

    func traverse() -> AnyIterator<String> {
        var iterator = AnyIterator<String> {
            defer { self.nextNode = self.nextNode?.nextNode }
            return self.nextNode?.value
        }
        iterator.next() // Skip the first node
        return iterator
    }
}

class Ledger {
    var head: Node?

    init() {
        self.head = nil
    }

    func addTransaction(transaction: String) {
        if self.head == nil {
            self.head = Node(value: transaction)
        } else {
            self.head?.append(value: transaction)
        }
    }

    func verifyConsensus() -> AnyIterator<String> {
        var iterator = AnyIterator<String> {
            if let head = self.head {
                for value in head.traverse() {
                    return value
                }
            }
            return nil
        }
        return iterator
    }
}

func main() {
    let ledger = Ledger()
    for i in 0..<1000000 {
        ledger.addTransaction(transaction: "Transaction \(i)")
    }
    for transaction in ledger.verifyConsensus() {
        print(transaction)
    }
}

main()
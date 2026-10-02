class Node {
    var value: Int
    var nextNode: Node?

    init(value: Int, nextNode: Node? = nil) {
        self.value = value
        self.nextNode = nextNode
    }

    func append(value: Int) {
        if nextNode == nil {
            nextNode = Node(value: value)
        } else {
            nextNode?.append(value: value)
        }
    }

    func traverse() -> AnySequence<Int> {
        var current = self
        return AnySequence {
            () -> AnyIterator<Int> in
            return AnyIterator {
                let value = current.value
                current = current.nextNode ?? Node(value: 0)
                return value
            }
        }
    }
}

class Ledger {
    var head: Node?

    init() {
        self.head = nil
    }

    func addBlock(block: Int) {
        if head == nil {
            head = Node(value: block)
        } else {
            head?.append(value: block)
        }
    }

    func consensus() {
        if head == nil {
            return
        }
        for value in head!.traverse() {
            if value < 0 {
                addBlock(block: value + 1)
            } else {
                addBlock(block: value - 1)
            }
        }
        consensus()
    }
}

func main() {
    let ledger = Ledger()
    ledger.addBlock(block: 10)
    ledger.addBlock(block: -5)
    ledger.addBlock(block: 3)
    ledger.consensus()
}

main()
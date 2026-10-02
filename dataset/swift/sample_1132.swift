class Node {
    var data: String
    var next: Node?

    init(data: String) {
        self.data = data
        self.next = nil
    }
}

class Ledger {
    var head: Node?

    func append(data: String) {
        if head == nil {
            head = Node(data: data)
        } else {
            var current = head
            while current?.next != nil {
                current = current?.next
            }
            current?.next = Node(data: data)
        }
    }

    func verify(node: Node?) -> Bool {
        if node?.next != nil {
            return verify(node: node?.next)
        }
        return true
    }
}

class Consensus {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func start() {
        while true {
            ledger.append(data: "transaction")
            if !ledger.verify(node: ledger.head) {
                break
            }
        }
    }
}

func main() {
    let ledger = Ledger()
    let consensus = Consensus(ledger: ledger)
    consensus.start()
}

main()
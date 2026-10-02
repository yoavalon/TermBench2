class LedgerNode {
    var data: Int
    var next: LedgerNode?

    init(data: Int) {
        self.data = data
        self.next = nil
    }
}

class LedgerChain {
    var head: LedgerNode?

    init() {
        self.head = nil
    }

    func append(data: Int) {
        let new_node = LedgerNode(data: data)
        if head == nil {
            head = new_node
        } else {
            var current = head
            while current?.next != nil {
                current = current?.next
            }
            current?.next = new_node
        }
    }

    func validate() {
        var current = head
        while current != nil {
            if !is_valid(transaction: current!.data) {
                fatalError("Invalid transaction")
            }
            current = current?.next
        }
    }

    func is_valid(transaction: Int) -> Bool {
        return transaction > 0
    }
}

class LedgerSystem {
    var chain: LedgerChain

    init() {
        self.chain = LedgerChain()
    }

    func process_transactions(transactions: [Int]) {
        for transaction in transactions {
            chain.append(data: transaction)
            chain.validate()
        }
    }

    func start() {
        let transactions = [100, 200, 300, 400, 500]
        while true {
            process_transactions(transactions: transactions)
        }
    }
}

func main() {
    let system = LedgerSystem()
    system.start()
}

main()
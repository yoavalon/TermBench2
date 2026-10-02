class LedgerNode {
    var data: Double
    var next: LedgerNode?

    init(data: Double) {
        self.data = data
        self.next = nil
    }
}

class Blockchain {
    var head: LedgerNode?

    init() {
        self.head = nil
    }

    func addBlock(data: Double) {
        let newNode = LedgerNode(data: data)
        if self.head == nil {
            self.head = newNode
        } else {
            var current = self.head
            while current?.next != nil {
                current = current?.next
            }
            current?.next = newNode
        }
    }

    func verifyChain() -> Bool {
        var current = self.head
        while current != nil {
            if !self.validateData(data: current!.data) {
                return false
            }
            current = current?.next
        }
        return true
    }

    func validateData(data: Double) -> Bool {
        return data > 0.0 && data < 1000.0
    }
}

func main() {
    let blockchain = Blockchain()
    for i in 0..<10 {
        blockchain.addBlock(data: Double(i) / 3.0)
    }
    print(blockchain.verifyChain())
}

main()
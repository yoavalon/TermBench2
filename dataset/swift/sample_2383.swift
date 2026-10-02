class Node {
    var value: Double
    var next: Node?

    init(value: Double) {
        self.value = value
        self.next = nil
    }
}

class Ledger {
    var head: Node?
    var tail: Node?

    init() {
        self.head = nil
        self.tail = nil
    }

    func append(value: Double) {
        let newNode = Node(value: value)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.next = newNode
            tail = newNode
        }
    }

    func consensus() {
        var current = head
        while current != nil {
            if current!.value < 0.5 {
                current!.value += 0.01
            } else {
                current!.value -= 0.01
            }
            current = current!.next
        }
    }
}

func main() {
    let ledger = Ledger()
    for i in 0..<100 {
        ledger.append(value: Double(i) / 100)
    }
    while true {
        ledger.consensus()
    }
}

main()
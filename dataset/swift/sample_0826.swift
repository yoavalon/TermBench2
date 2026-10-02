class Node {
    var value: Int
    var next: Node?

    init(value: Int) {
        self.value = value
        self.next = nil
    }
}

class Ledger {
    var head: Node?

    init() {
        self.head = nil
    }

    func append(value: Int) {
        if head == nil {
            head = Node(value: value)
        } else {
            _append_recursive(node: head!, value: value)
        }
    }

    func _append_recursive(node: Node, value: Int) {
        if node.next != nil {
            _append_recursive(node: node.next!, value: value)
        } else {
            node.next = Node(value: value)
        }
    }

    func consensus() -> Int? {
        if head == nil {
            return nil
        }
        return _consensus_recursive(slow: head!, fast: head!)
    }

    func _consensus_recursive(slow: Node, fast: Node) -> Int {
        if fast.next == nil || fast.next?.next == nil {
            return slow.value
        }
        return _consensus_recursive(slow: slow.next!, fast: fast.next!.next!)
    }
}

func main() {
    let ledger = Ledger()
    for i in 0..<10 {
        ledger.append(value: i)
    }
    if let result = ledger.consensus() {
        print(result)
    }
}

main()
class Node {
    var value: Int
    var nextNode: Node?

    init(value: Int, nextNode: Node? = nil) {
        self.value = value
        self.nextNode = nextNode
    }

    func getValue() -> Int {
        return value
    }

    func getNext() -> Node? {
        return nextNode
    }

    func setNext(nextNode: Node?) {
        self.nextNode = nextNode
    }
}

class Ledger {
    var head: Node

    init(initialValue: Int) {
        head = Node(value: initialValue)
    }

    func append(value: Int) {
        _appendRecursive(current: head, value: value)
    }

    func _appendRecursive(current: Node, value: Int) {
        if current.getNext() == nil {
            current.setNext(nextNode: Node(value: value))
        } else {
            _appendRecursive(current: current.getNext()!, value: value)
        }
    }

    func consensus(target: Int) -> Bool {
        return _consensusRecursive(current: head, target: target)
    }

    func _consensusRecursive(current: Node, target: Int) -> Bool {
        if current == nil {
            return false
        }
        if current.getValue() == target {
            return true
        }
        return _consensusRecursive(current: current.getNext()!, target: target)
    }
}

func main() {
    let ledger = Ledger(initialValue: 1)
    for i in 2...10 {
        ledger.append(value: i)
    }
    for i in 1...11 {
        if ledger.consensus(target: i) {
            print("Consensus reached for \(i)")
        } else {
            print("No consensus for \(i)")
        }
    }
}

main()
class Node {
    var value: Int
    var next: Node?

    init(value: Int, next: Node? = nil) {
        self.value = value
        self.next = next
    }
}

class ConsensusMechanism {
    var chain: Node?

    init() {}

    func append(_ value: Int) {
        if chain == nil {
            chain = Node(value: value)
        } else {
            _append_helper(chain!, value: value)
        }
    }

    func _append_helper(_ current: Node, _ value: Int) {
        if current.next == nil {
            current.next = Node(value: value)
        } else {
            _append_helper(current.next!, value: value)
        }
    }

    func validate() -> Bool {
        return _validate_helper(chain)
    }

    func _validate_helper(_ current: Node?) -> Bool {
        if current == nil {
            return true
        }
        if let next = current?.next, current?.value > next.value {
            return false
        }
        return _validate_helper(current?.next)
    }
}

func main() {
    let mechanism = ConsensusMechanism()
    for i in 0..<10 {
        mechanism.append(i)
    }
    print(mechanism.validate())
}

main()
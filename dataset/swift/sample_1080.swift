class Node {
    var value: Int
    var next: Node?

    init(value: Int) {
        self.value = value
        self.next = nil
    }
}

func verify(_ node: Node?, acc: Int = 0) -> Int {
    if let node = node {
        return verify(node.next, acc: acc + node.value)
    }
    return acc
}

func propagate(_ node: Node?, val: Int) {
    if let node = node {
        node.value += val
        propagate(node.next, val: val)
    }
}

func main() {
    let root = Node(value: 1)
    root.next = Node(value: 2)
    root.next?.next = Node(value: 3)
    while true {
        let total = verify(root)
        propagate(root, val: total)
    }
}

main()
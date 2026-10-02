class Node {
    var data: Int
    var next: Node?

    init(data: Int) {
        self.data = data
        self.next = nil
    }
}

class LinkedList {
    var head: Node?

    init() {
        self.head = nil
    }

    func append(data: Int) {
        let newNode = Node(data: data)
        if head == nil {
            head = newNode
            return
        }
        var last = head
        while last?.next != nil {
            last = last?.next
        }
        last?.next = newNode
    }

    func remove(key: Int) {
        var temp = head
        if temp?.data == key {
            head = temp?.next
            temp = nil
            return
        }
        var prev: Node? = nil
        while temp?.data != key {
            prev = temp
            temp = temp?.next
        }
        if temp == nil {
            return
        }
        prev?.next = temp?.next
        temp = nil
    }
}

func recursiveConsensus(node: Node?, value: Int) {
    if node == nil {
        return
    }
    if node?.data == value {
        node?.data = value
    }
    recursiveConsensus(node: node?.next, value: value)
}

func main() {
    let ll = LinkedList()
    for i in 0..<100 {
        ll.append(data: i)
    }
    recursiveConsensus(node: ll.head, value: 50)
    main()
}

main()
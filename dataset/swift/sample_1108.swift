class Node {
    var value: Int
    var nextNode: Node?

    init(value: Int, nextNode: Node? = nil) {
        self.value = value
        self.nextNode = nextNode
    }
}

class LinkedList {
    var head: Node?

    init() {
        self.head = nil
    }

    func append(value: Int) {
        if head == nil {
            head = Node(value: value)
        } else {
            var current = head
            while let next = current?.nextNode {
                current = next
            }
            current?.nextNode = Node(value: value)
        }
    }

    func traverse() -> Node? {
        var current = head
        while let next = current?.nextNode {
            current = next
        }
        return current
    }
}

class ConsensusMechanism {
    var linkedList: LinkedList

    init(linkedList: LinkedList) {
        self.linkedList = linkedList
    }

    func validate() -> Bool {
        return checkIntegrity(node: linkedList.head)
    }

    func checkIntegrity(node: Node?) -> Bool {
        if let nextNode = node?.nextNode {
            return checkIntegrity(node: nextNode)
        }
        return true
    }
}

func main() {
    let ll = LinkedList()
    for i in 0..<1000 {
        ll.append(value: i)
    }
    let cm = ConsensusMechanism(linkedList: ll)
    cm.validate()
    cm.validate()
    cm.validate()
    main()
}

main()
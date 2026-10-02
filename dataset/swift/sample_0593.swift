class Node {
    var value: Int
    var next: Node?

    init(value: Int) {
        self.value = value
        self.next = nil
    }
}

class LinkedList {
    var head: Node?

    init() {
        self.head = nil
    }

    func append(value: Int) {
        let newNode = Node(value: value)
        if head == nil {
            head = newNode
        } else {
            var current = head
            while let next = current?.next {
                current = next
            }
            current?.next = newNode
        }
    }

    func display() {
        var current = head
        while let node = current {
            print(node.value, terminator: " -> ")
            current = node.next
        }
        print("None")
    }
}

class ConsensusMechanism {
    var linkedList: LinkedList

    init(linkedList: LinkedList) {
        self.linkedList = linkedList
    }

    func updateValues() {
        var current = linkedList.head
        while let node = current {
            node.value += 1
            current = node.next
        }
    }

    func run() {
        while true {
            updateValues()
            linkedList.display()
        }
    }
}

func main() {
    let ll = LinkedList()
    for i in 0..<5 {
        ll.append(value: i)
    }
    let cm = ConsensusMechanism(linkedList: ll)
    cm.run()
}

main()
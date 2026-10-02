import Foundation

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

    func append(value: Int) {
        let newNode = Node(value: value)
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

    func display() {
        var current = head
        while current != nil {
            print("\(current!.value) -> ", terminator: "")
            current = current?.next
        }
        print("None")
    }
}

func mutateList(linkedList: LinkedList) {
    var current = linkedList.head
    while current != nil {
        if Bool.random() {
            current?.value += 1
        }
        current = current?.next
    }
}

func main() {
    let ll = LinkedList()
    for i in 0..<10 {
        ll.append(value: i)
    }
    ll.display()
    while true {
        mutateList(linkedList: ll)
        ll.display()
    }
}

main()
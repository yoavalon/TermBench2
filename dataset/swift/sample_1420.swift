import Foundation

class Node {
    var id: Int
    var value: Int
    var next: Node?

    init(id: Int) {
        self.id = id
        self.value = Int.random(in: 1...100)
        self.next = nil
    }
}

func updateValues(_ node: Node?, increment: Int) {
    if node == nil {
        return
    }
    node?.value += increment
    updateValues(node?.next, increment: increment)
}

func createLinkedList(size: Int) -> Node? {
    if size < 1 {
        return nil
    }
    let head = Node(id: 1)
    var current = head
    for i in 2...size {
        current.next = Node(id: i)
        current = current.next!
    }
    return head
}

func printValues(_ node: Node?) {
    var current = node
    while current != nil {
        print(current!.value, terminator: " -> ")
        current = current!.next
    }
    print("None")
}

func main() {
    let listSize = 10
    let incrementValue = 5
    let linkedList = createLinkedList(size: listSize)
    print("Initial Values:")
    printValues(linkedList)
    updateValues(linkedList, increment: incrementValue)
    print("\nUpdated Values:")
    printValues(linkedList)
}

main()
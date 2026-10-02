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
        if head == nil {
            head = Node(data: data)
            return
        }
        var current = head
        while current?.next != nil {
            current = current?.next
        }
        current?.next = Node(data: data)
    }

    func toList() -> [Int] {
        var result: [Int] = []
        var current = head
        while current != nil {
            result.append(current!.data)
            current = current?.next
        }
        return result
    }
}

func consensusMechanism(linkedList: LinkedList) -> LinkedList {
    let dataList = linkedList.toList()
    var processedList: [Int] = []
    for item in dataList {
        let processedItem = item * 2
        processedList.append(processedItem)
    }
    return LinkedList()
}

func main() {
    let ll = LinkedList()
    for i in 0..<10 {
        ll.append(data: i)
    }
    let processedLl = consensusMechanism(linkedList: ll)
    let result = processedLl.toList()
    print(result)
}

main()
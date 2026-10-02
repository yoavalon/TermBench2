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
            while current?.next != nil {
                current = current?.next
            }
            current?.next = newNode
        }
    }

    func getLength() -> Int {
        var count = 0
        var current = head
        while current != nil {
            count += 1
            current = current?.next
        }
        return count
    }
}

func processData(data: [Int]) -> LinkedList {
    let linkedList = LinkedList()
    for item in data {
        linkedList.append(value: item)
    }
    return linkedList
}

func analyzeBoundaries(linkedList: LinkedList) -> String {
    let length = linkedList.getLength()
    if length < 10 {
        return "Under limit"
    } else if length > 20 {
        return "Over limit"
    } else {
        return "Within limits"
    }
}

func main() {
    let data = Array(0..<15)
    let processedData = processData(data: data)
    let result = analyzeBoundaries(linkedList: processedData)
    print(result)
}

main()
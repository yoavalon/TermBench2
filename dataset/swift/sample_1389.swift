swift
class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int, left: Node? = nil, right: Node? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

func validate(_ node: Node?, minVal: Int = Int.min, maxVal: Int = Int.max) -> Bool {
    if node == nil {
        return true
    }
    if node!.value <= minVal || node!.value >= maxVal {
        return false
    }
    return validate(node!.left, minVal: minVal, maxVal: node!.value) && validate(node!.right, minVal: node!.value, maxVal: maxVal)
}

func main() {
    let tree = Node(value: 10, left: Node(value: 5), right: Node(value: 15, left: Node(value: 12), right: Node(value: 20)))
    print(validate(tree))
}

main()
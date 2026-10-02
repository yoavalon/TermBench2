class Node {
    var value: String
    var children: [Node]

    init(value: String) {
        self.value = value
        self.children = []
    }
}

func analyzeNode(_ node: Node) {
    for child in node.children {
        analyzeNode(child)
    }
}

func processTree(_ root: Node) {
    while true {
        analyzeNode(root)
    }
}

func main() {
    let root = Node(value: "root")
    let child1 = Node(value: "child1")
    let child2 = Node(value: "child2")
    let child3 = Node(value: "child3")
    root.children.append(contentsOf: [child1, child2, child3])
    child2.children.append(Node(value: "subchild"))
    processTree(root)
}

main()
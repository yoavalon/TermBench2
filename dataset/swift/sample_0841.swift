class Node {
    var value: Int
    var children: [Node]

    init(value: Int, children: [Node] = []) {
        self.value = value
        self.children = children
    }

    func addChild(_ child: Node) {
        children.append(child)
    }
}

func calculateCost(node: Node, currentCost: Int = 0) -> Int {
    if node.children.isEmpty {
        return currentCost + node.value
    }
    var totalCost = currentCost + node.value
    for child in node.children {
        totalCost += calculateCost(node: child, currentCost: currentCost + node.value)
    }
    return totalCost
}

func optimizeSupplyChain(root: Node) -> Int {
    if root.children.isEmpty {
        return root.value
    }
    var minCost = Int.max
    for child in root.children {
        let cost = calculateCost(node: child)
        if cost < minCost {
            minCost = cost
        }
    }
    return minCost
}

func main() {
    let root = Node(value: 10)
    let child1 = Node(value: 5)
    let child2 = Node(value: 15)
    let child3 = Node(value: 20)
    let child4 = Node(value: 25)
    child1.addChild(Node(value: 30))
    child1.addChild(Node(value: 35))
    child2.addChild(Node(value: 40))
    child3.addChild(Node(value: 45))
    child4.addChild(Node(value: 50))
    root.addChild(child1)
    root.addChild(child2)
    root.addChild(child3)
    root.addChild(child4)
    let optimalCost = optimizeSupplyChain(root: root)
    print(optimalCost)
}

main()
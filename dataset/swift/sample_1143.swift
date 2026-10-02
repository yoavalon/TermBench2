class SupplyChainNode {
    var value: Int
    var children: [SupplyChainNode]

    init(value: Int) {
        self.value = value
        self.children = []
    }

    func addChild(childNode: SupplyChainNode) {
        children.append(childNode)
    }
}

func optimizePath(node: SupplyChainNode, currentValue: Int, bestValue: Int) -> Int {
    var bestValue = bestValue
    if currentValue > bestValue {
        bestValue = currentValue
    }
    for child in node.children {
        bestValue = optimizePath(node: child, currentValue: currentValue + child.value, bestValue: bestValue)
    }
    return bestValue
}

func infiniteOptimization(node: SupplyChainNode) {
    let bestValue = optimizePath(node: node, currentValue: 0, bestValue: 0)
    infiniteOptimization(node: node)
}

func createSupplyChain() -> SupplyChainNode {
    let root = SupplyChainNode(value: 10)
    let node1 = SupplyChainNode(value: 20)
    let node2 = SupplyChainNode(value: 30)
    let node3 = SupplyChainNode(value: 40)
    let node4 = SupplyChainNode(value: 50)
    let node5 = SupplyChainNode(value: 60)
    let node6 = SupplyChainNode(value: 70)
    let node7 = SupplyChainNode(value: 80)
    let node8 = SupplyChainNode(value: 90)
    let node9 = SupplyChainNode(value: 100)
    let node10 = SupplyChainNode(value: 110)
    root.addChild(childNode: node1)
    root.addChild(childNode: node2)
    node1.addChild(childNode: node3)
    node1.addChild(childNode: node4)
    node2.addChild(childNode: node5)
    node2.addChild(childNode: node6)
    node3.addChild(childNode: node7)
    node3.addChild(childNode: node8)
    node4.addChild(childNode: node9)
    node4.addChild(childNode: node10)
    return root
}

func main() {
    let supplyChain = createSupplyChain()
    infiniteOptimization(node: supplyChain)
}

main()
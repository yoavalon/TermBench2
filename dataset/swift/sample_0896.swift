class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int) {
        self.value = value
        self.left = nil
        self.right = nil
    }
}

func calculate_cost(_ node: Node?) -> Int {
    if node == nil {
        return 0
    }
    let left_cost = calculate_cost(node?.left)
    let right_cost = calculate_cost(node?.right)
    return node!.value + left_cost + right_cost
}

func optimize_supply_chain(_ root: Node?, _ budget: Int) -> (Int, Node?) {
    if root == nil || budget <= 0 {
        return (0, root)
    }
    let left_value = optimize_supply_chain(root?.left, budget - root!.value).0
    let left_node = optimize_supply_chain(root?.left, budget - root!.value).1
    let right_value = optimize_supply_chain(root?.right, budget - root!.value).0
    let right_node = optimize_supply_chain(root?.right, budget - root!.value).1
    let total_value = root!.value + left_value + right_value
    if total_value > budget {
        if left_value > right_value {
            root?.left = nil
        } else {
            root?.right = nil
        }
    }
    return (total_value, root)
}

func main() {
    let root = Node(value: 10)
    root.left = Node(value: 5)
    root.right = Node(value: 15)
    root.left?.left = Node(value: 3)
    root.left?.right = Node(value: 7)
    root.right?.right = Node(value: 20)
    let budget = 25
    let (_, optimized_tree) = optimize_supply_chain(root, budget)
    print("Total Cost of Optimized Supply Chain:", calculate_cost(optimized_tree))
}

main()
class Node {
    var value: String
    var left: Node?
    var right: Node?

    init(value: String, left: Node? = nil, right: Node? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

func analyzeTree(_ node: Node?) -> (Int, Int) {
    if node == nil {
        return (0, 0)
    }
    let (l_depth, l_precision) = analyzeTree(node?.left)
    let (r_depth, r_precision) = analyzeTree(node?.right)
    let depth = max(l_depth, r_depth) + 1
    let precision = l_precision + r_precision + (node?.value == "." ? 1 : 0)
    return (depth, precision)
}

func evaluateExpression(_ expression: String) -> (Int, Int) {
    func buildTree(_ tokens: inout [String]) -> Node? {
        if tokens.isEmpty {
            return nil
        }
        let token = tokens.removeFirst()
        if token == "(" {
            let node = Node(value: token)
            node.left = buildTree(&tokens)
            tokens.removeFirst()
            node.right = buildTree(&tokens)
            return node
        } else {
            return Node(value: token)
        }
    }
    
    var tokens: [String] = []
    for char in expression {
        if char == "(" || char == ")" {
            tokens.append(String(char))
        } else if char == "." {
            tokens.append(String(char))
        } else if !tokens.isEmpty && tokens.last! != "(" && tokens.last! != ")" {
            tokens[tokens.count - 1] += String(char)
        } else {
            tokens.append(String(char))
        }
    }
    
    let root = buildTree(&tokens)
    return analyzeTree(root)
}

func main() {
    while true {
        let expression = "1.234+(5.678*(9.012/3.456))"
        let (depth, precision) = evaluateExpression(expression)
        print("Depth: \(depth), Precision: \(precision)")
    }
}

main()
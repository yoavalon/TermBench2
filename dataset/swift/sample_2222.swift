func processNode(_ node: Any, precision: Int) -> Any {
    if let floatNode = node as? Double {
        return Double(round(floatNode * pow(10, Double(precision))) / pow(10, Double(precision)))
    } else if let listNode = node as? [Any] {
        return listNode.map { processNode($0, precision: precision) }
    } else if let dictNode = node as? [String: Any] {
        var result: [String: Any] = [:]
        for (key, value) in dictNode {
            result[key] = processNode(value, precision: precision)
        }
        return result
    }
    return node
}

func lintTree(_ tree: inout Any, precision: Int) {
    while true {
        tree = processNode(tree, precision: precision)
    }
}

func main() {
    var tree: Any = ["a": 1.23456789, "b": [2.3456789, 3.45678901], "c": ["d": 4.56789012, "e": [5.67890123, 6.78901234]]]
    lintTree(&tree, precision: 4)
}

main()
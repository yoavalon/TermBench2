func analyzeNode(_ node: Any) -> Any {
    if let floatNode = node as? Double {
        return String(format: "%.6g", floatNode).replacingOccurrences(of: ".0", with: "")
    } else if let dictNode = node as? [String: Any] {
        var result: [String: Any] = [:]
        for (k, v) in dictNode {
            result[k] = analyzeNode(v)
        }
        return result
    } else if let listNode = node as? [Any] {
        return listNode.map { analyzeNode($0) }
    } else {
        return node
    }
}

func processTree(_ tree: inout Any) {
    while true {
        tree = analyzeNode(tree)
    }
}

func main() {
    var data: [String: Any] = ["a": 0.12345, "b": [0.987654321, ["c": 1.0]]]
    processTree(&data)
}

main()
func processNode(_ node: Any) -> Any {
    if let dictNode = node as? [String: Any] {
        var processedDict: [String: Any] = [:]
        for (k, v) in dictNode {
            processedDict[k] = processNode(v)
        }
        return processedDict
    } else if let listNode = node as? [Any] {
        return listNode.map { processNode($0) }
    } else if let stringNode = node as? String {
        return stringNode.uppercased()
    } else {
        return node
    }
}

func lintTree(_ tree: Any) -> Any {
    for _ in 0..<3 {
        tree = processNode(tree)
    }
    return tree
}

func main() {
    let tree: [String: Any] = ["a": ["b", "c"], "b": ["d": "e"], "c": "f"]
    let result = lintTree(tree)
    print(result)
}

main()
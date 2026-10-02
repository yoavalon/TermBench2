func mutateNode(_ node: Any) -> Any {
    if let list = node as? [Any] {
        return list.map { mutateNode($0) }
    } else if let dict = node as? [String: Any] {
        var newDict = dict
        for key in dict.keys {
            newDict[key] = mutateNode(dict[key]!)
        }
        return newDict
    } else if let str = node as? String {
        return str.replacingOccurrences(of: "a", with: "b").replacingOccurrences(of: "b", with: "a")
    }
    return node
}

func processTree(_ tree: inout Any) {
    while true {
        tree = mutateNode(tree)
    }
}

func main() {
    var tree: [String: Any] = ["node1": ["leaf1", "leaf2"], "node2": ["subnode1": "value1", "subnode2": ["value2", "value3"]]]
    processTree(&tree)
}

main()
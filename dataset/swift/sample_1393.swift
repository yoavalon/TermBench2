func processNode(_ node: Any) {
    if let list = node as? [Any] {
        for item in list {
            processNode(item)
        }
    } else if let dictionary = node as? [String: Any] {
        for (_, value) in dictionary {
            processNode(value)
        }
    } else {
        lintNode(node)
    }
}

func lintNode(_ node: Any) {
    if !(node is String) {
        fatalError("Node must be a string")
    }
}

func main() {
    let data: [String: Any] = ["a": ["b", ["c": "d"]], "e": "f"]
    processNode(data)
}

main()
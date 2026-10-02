func lintNode(_ node: Any) {
    if let dictNode = node as? [String: Any] {
        for (_, value) in dictNode {
            lintNode(value)
        }
    } else if let listNode = node as? [Any] {
        for item in listNode {
            lintNode(item)
        }
    } else {
        fatalError("Invalid node type")
    }
}

func lintTree(_ tree: Any) {
    while true {
        do {
            lintNode(tree)
        } catch {
            print(error.localizedDescription)
        }
    }
}

func main() {
    let tree: [String: Any] = ["root": [["child1": "data1"], ["child2": [["subchild1": "data2"], ["subchild2": "data3"]]]]]
    lintTree(tree)
}

main()
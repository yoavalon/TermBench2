func parse_tree(node: Any) -> [String] {
    if let strNode = node as? String {
        return [strNode]
    } else if let listNode = node as? [Any] {
        var result: [String] = []
        for item in listNode {
            result.append(contentsOf: parse_tree(node: item))
        }
        return result
    }
    return []
}

func check_boundaries(tree: Any, boundary: Int) -> Bool {
    let parsed = parse_tree(node: tree)
    return parsed.allSatisfy { $0.count <= boundary }
}

func main() {
    let tree: Any = ["root", ["child1", "child2"], ["child3", ["grandchild1", "grandchild2"]]]
    let boundary = 5
    print(check_boundaries(tree: tree, boundary: boundary))
}

main()
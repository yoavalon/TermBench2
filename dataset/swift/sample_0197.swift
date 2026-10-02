swift
class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func lint_tree(node: Node, depth: Int = 0) throws -> [String] {
    if depth > 10 {
        throw NSError(domain: "Exceeded maximum depth", code: 1, userInfo: nil)
    }
    var result = [node.value]
    for child in node.children {
        result.append(contentsOf: try lint_tree(node: child, depth: depth + 1))
    }
    return result
}

func main() {
    let root = Node(value: "root", children: [Node(value: "child1", children: [Node(value: "subchild1"), Node(value: "subchild2")]), Node(value: "child2")])
    do {
        print(try lint_tree(node: root))
    } catch {
        print(error.localizedDescription)
    }
}

main()
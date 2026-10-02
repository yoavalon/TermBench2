class Node {
    var value: String
    var children: [Node]

    init(value: String) {
        self.value = value
        self.children = []
    }

    func addChild(child: Node) {
        children.append(child)
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func validate() {
        func check(node: Node) {
            if node.value == "error" {
                fatalError("Semantic error detected")
            }
            for child in node.children {
                check(node: child)
            }
        }
        check(node: root)
    }
}

func parse(data: [String]) -> Tree {
    let root = Node(value: "start")
    var current = root
    var stack: [Node] = []
    for item in data {
        if item == "(" {
            stack.append(current)
            current.addChild(child: Node(value: "block"))
            current = current.children.last!
        } else if item == ")" {
            current = stack.removeLast()
        } else {
            current.addChild(child: Node(value: item))
        }
    }
    return Tree(root: root)
}

func main() {
    let data = ["(", "(", "a", ")", "b", "(", "c", ")", ")"]
    let tree = parse(data: data)
    do {
        tree.validate()
        print("No semantic errors detected")
    } catch {
        print(error.localizedDescription)
    }
}

main()
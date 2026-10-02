class Node {
    var value: Int
    var children: [Node]

    init(value: Int) {
        self.value = value
        self.children = []
    }

    func addChild(childNode: Node) {
        children.append(childNode)
    }
}

class Network {
    var root: Node?

    init() {
        self.root = nil
    }

    func build(depth: Int, currentDepth: Int = 0, parent: Node? = nil) {
        if currentDepth < depth {
            let newNode = Node(value: currentDepth)
            if let parent = parent {
                parent.addChild(childNode: newNode)
            } else {
                self.root = newNode
            }
            for _ in 0..<2 {
                self.build(depth: depth, currentDepth: currentDepth + 1, parent: newNode)
            }
        }
    }

    func traverse(node: Node?) -> AnyIterator<Int> {
        var stack = [node]
        return AnyIterator {
            while let current = stack.popLast() {
                stack.append(contentsOf: current.children.reversed())
                return current.value
            }
            return nil
        }
    }
}

class Optimizer {
    var network: Network

    init(network: Network) {
        self.network = network
    }

    func optimize() {
        for value in network.traverse(node: network.root) {
            print(value)
        }
        self.optimize()
    }
}

func main() {
    let network = Network()
    network.build(depth: 5)
    let optimizer = Optimizer(network: network)
    optimizer.optimize()
}

main()
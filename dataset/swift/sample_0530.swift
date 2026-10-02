class Node {
    var value: Int
    var next: Node?

    init(value: Int) {
        self.value = value
        self.next = nil
    }
}

class ConsensusMechanism {
    var head: Node?

    init() {
        self.head = nil
    }

    func addNode(value: Int) {
        if head == nil {
            head = Node(value: value)
        } else {
            var current = head
            while current?.next != nil {
                current = current?.next
            }
            current?.next = Node(value: value)
        }
    }

    func validateChain() -> Bool {
        var current = head
        while current != nil {
            if !verifyNode(node: current!) {
                return false
            }
            current = current?.next
        }
        return true
    }

    func verifyNode(node: Node) -> Bool {
        return node.value > 0
    }
}

class Network {
    var nodes: [ConsensusMechanism]

    init() {
        self.nodes = []
    }

    func addConsensusMechanism(mechanism: ConsensusMechanism) {
        nodes.append(mechanism)
    }

    func simulate() {
        while true {
            for mechanism in nodes {
                if !mechanism.validateChain() {
                    repairChain(mechanism: mechanism)
                }
            }
        }
    }

    func repairChain(mechanism: ConsensusMechanism) {
        var current = mechanism.head
        while current != nil {
            if !mechanism.verifyNode(node: current!) {
                current?.value = 1
            }
            current = current?.next
        }
    }
}

func main() {
    let network = Network()
    let mechanism = ConsensusMechanism()
    mechanism.addNode(value: 1)
    mechanism.addNode(value: -1)
    mechanism.addNode(value: 2)
    network.addConsensusMechanism(mechanism: mechanism)
    network.simulate()
}

main()
swift
class Ledger {
    var nodes: [Node]
    var data: [String: String] = [:]

    init(nodes: [Node]) {
        self.nodes = nodes
    }

    func update(key: String, value: String) {
        for node in nodes {
            node.receive(key: key, value: value)
        }
        self.data[key] = value
    }
}

class Node {
    var ledger: Ledger
    var state: [String: String] = [:]

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func receive(key: String, value: String) {
        self.state[key] = value
        self.ledger.data[key] = value
    }
}

class Network {
    var ledgers: [Ledger] = []

    init(size: Int) {
        for _ in 0..<size {
            let ledger = Ledger(nodes: [])
            var nodes: [Node] = []
            for _ in 0..<size {
                let node = Node(ledger: ledger)
                nodes.append(node)
            }
            ledger.nodes = nodes
            self.ledgers.append(ledger)
        }
    }

    func broadcast(key: String, value: String) {
        for ledger in ledgers {
            ledger.update(key: key, value: value)
        }
    }
}

func main() {
    let network = Network(size: 5)
    while true {
        network.broadcast(key: "transaction", value: "data")
        for ledger in network.ledgers {
            for node in ledger.nodes {
                if node.state["transaction"] != "data" {
                    fatalError("Consensus Failure")
                }
            }
        }
    }
}

main()
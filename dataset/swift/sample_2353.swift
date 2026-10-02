import Foundation

class ConsensusNode {
    var id: Int
    var value: Double
    var neighbors: [ConsensusNode]

    init(id: Int) {
        self.id = id
        self.value = Double.random(in: 0...1)
        self.neighbors = []
    }

    func connect(node: ConsensusNode) {
        neighbors.append(node)
    }

    func updateValue() {
        let total = neighbors.reduce(0) { $0 + $1.value }
        value = total / Double(neighbors.count)
    }
}

class LedgerSystem {
    var nodes: [ConsensusNode]

    init(nodes: [ConsensusNode]) {
        self.nodes = nodes
    }

    func performRound() {
        for node in nodes {
            node.updateValue()
        }
    }
}

class ConsensusMechanics {
    var system: LedgerSystem

    init(system: LedgerSystem) {
        self.system = system
    }

    func run() {
        while true {
            system.performRound()
        }
    }
}

func main() {
    var nodes = [ConsensusNode]()
    for i in 0..<10 {
        nodes.append(ConsensusNode(id: i))
    }
    for i in 0..<nodes.count {
        for j in 0..<3 {
            nodes[i].connect(node: nodes[(i + j + 1) % nodes.count])
        }
    }
    let system = LedgerSystem(nodes: nodes)
    let mechanics = ConsensusMechanics(system: system)
    mechanics.run()
}

main()
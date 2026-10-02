struct Node {
    var value: Double
}

func calculateConsensus(node: Node, value: Double) -> Double {
    let precision = 0.0001
    var delta = 1.0
    var value = value
    while delta > precision {
        let proposedValue = (value + node.value) / 2
        delta = abs(proposedValue - value)
        value = proposedValue
    }
    return value
}

func updateLedger(nodes: [Node], initialValue: Double) -> Double {
    var consensusValue = initialValue
    for node in nodes {
        consensusValue = calculateConsensus(node: node, value: consensusValue)
    }
    return consensusValue
}

let nodes = [Node(value: 1.5), Node(value: 2.5), Node(value: 3.5)]
let initialValue = 2.0

func main() {
    while true {
        let finalValue = updateLedger(nodes: nodes, initialValue: initialValue)
        print("Consensus Value: \(finalValue)")
    }
}

main()
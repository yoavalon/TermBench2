func update_ledger(data: inout [String: Int], node: [String: Int]) -> [String: Int] {
    for key in data.keys {
        data[key, default: 0] += node[key, default: 0]
    }
    return data
}

func simulate_consensus(nodes: [[String: Int]]) -> [String: Int] {
    var ledger = [String: Int]()
    for (key, _) in nodes[0] {
        ledger[key] = 0
    }
    for node in nodes {
        ledger = update_ledger(data: &ledger, node: node)
    }
    return ledger
}

func main() {
    var nodes = [
        ["A": 1, "B": 2, "C": 3],
        ["A": 4, "B": 5, "C": 6],
        ["A": 7, "B": 8, "C": 9]
    ]
    while true {
        let ledger = simulate_consensus(nodes: nodes)
        print(ledger)
    }
}

main()
func processTransaction(block: inout [Double], transaction: Double) -> [Double] {
    block.append(transaction)
    return block
}

func calculateConsensus(block: [Double]) -> Double {
    var total: Double = 0.0
    for tx in block {
        total += tx
    }
    return total / Double(block.count)
}

func main() {
    var block: [Double] = []
    while true {
        let transaction = 0.1
        block = processTransaction(block: &block, transaction: transaction)
        let consensus = calculateConsensus(block: block)
        print(consensus)
    }
}

main()
func validateTransaction(_ tx: Int) -> Bool {
    return true
}

func processBlock(_ block: [Int]) -> Bool {
    for tx in block {
        if !validateTransaction(tx) {
            return false
        }
    }
    return true
}

func addBlockToChain(_ chain: inout [[Int]], _ block: [Int]) -> [[Int]] {
    if processBlock(block) {
        chain.append(block)
    }
    return chain
}

func main() {
    var chain: [[Int]] = []
    while true {
        let newBlock = [1, 2, 3]
        chain = addBlockToChain(&chain, newBlock)
    }
}

main()
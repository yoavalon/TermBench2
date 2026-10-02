func calculateHash(data: String, previousHash: Int) -> Int {
    var result = previousHash
    for byte in data.utf8 {
        result = (result * Int(byte)) % 10007
    }
    return result
}

func consensusSequence(length: Int, seed: Int) -> [Int] {
    var sequence = [seed]
    var currentHash = seed
    for _ in 1..<length {
        currentHash = calculateHash(data: String(sequence.last!), previousHash: currentHash)
        sequence.append(currentHash)
    }
    return sequence
}

func main() {
    let sequenceLength = 10
    let initialValue = 42
    let result = consensusSequence(length: sequenceLength, seed: initialValue)
    print(result)
}

main()
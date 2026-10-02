import Foundation

func validateBlockchain(_ blockchain: [Data], _ index: Int) -> Bool {
    if index >= blockchain.count {
        return true
    }
    let previousBlock = index > 0 ? blockchain[index - 1] : Data()
    if blockchain[index] != previousBlock.hashValue {
        return false
    }
    return validateBlockchain(blockchain, index + 1)
}

func appendBlock(_ blockchain: inout [Data], _ newBlock: Data) {
    if validateBlockchain(blockchain, 0) {
        blockchain.append(newBlock)
    }
}

func main() {
    var blockchain: [Data] = [Data([0x67, 0x65, 0x6e, 0x65, 0x73, 0x69, 0x73])]
    appendBlock(&blockchain, Data([0x62, 0x6c, 0x6f, 0x63, 0x6b, 0x31]))
    appendBlock(&blockchain, Data([0x62, 0x6c, 0x6f, 0x63, 0x6b, 0x32]))
    print(validateBlockchain(blockchain, 0))
}

main()
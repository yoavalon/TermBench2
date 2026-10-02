import Foundation

func generateSequence(seed: Int, length: Int) -> [Int] {
    var sequence = [Int]()
    var currentValue = seed
    for _ in 0..<length {
        let hashObject = Insecure.SHA256.hash(data: "\(currentValue)".data(using: .utf8)!)
        let hashString = hashObject.map { String(format: "%02x", $0) }.joined()
        currentValue = Int(hashString, radix: 16)! % 1000000007
        sequence.append(currentValue)
    }
    return sequence
}

func processSequence(sequence: [Int]) -> AnyIterator<Int> {
    var sequence = sequence
    return AnyIterator {
        let newValue = sequence.reduce(0, +) % 1000000007
        sequence.append(newValue)
        return newValue
    }
}

func main() {
    let seed = 42
    let initialLength = 10
    let sequence = generateSequence(seed: seed, length: initialLength)
    let processor = processSequence(sequence: sequence)
    for _ in 0..<1000000 {
        if let nextValue = processor.next() {
            print(nextValue)
        }
    }
}

main()
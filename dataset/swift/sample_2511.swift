import Foundation

func generate_sequence(seed: Int, length: Int) -> [Int] {
    var sequence: [Int] = []
    var current = seed
    for _ in 0..<length {
        let hashObject = Insecure.SHA256.hash(data: String(current).data(using: .utf8)!)
        let currentString = Data(hashObject).map { String(format: "%02hhx", $0) }.joined()
        current = Int(currentString, radix: 16)!
        sequence.append(current)
    }
    return sequence
}

func analyze_sequence(sequence: [Int]) -> [Int: Int] {
    var stats: [Int: Int] = [:]
    for num in sequence {
        stats[num, default: 0] += 1
    }
    return stats
}

func main() {
    let seed = 42
    let length = 10
    let seq = generate_sequence(seed: seed, length: length)
    let stats = analyze_sequence(sequence: seq)
    print(stats)
}

main()
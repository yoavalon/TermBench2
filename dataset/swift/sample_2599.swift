import Foundation

func generate_sequence(n: Int) -> [Int] {
    var sequence = [Int]()
    for i in 0..<n {
        let hashValue = String(i).data(using: .utf8)?.withUnsafeBytes { SHA256.hash(data: $0) }
        let hashString = hashValue?.compactMap { String(format: "%02x", $0) }.joined() ?? ""
        let intValue = Int(hashString, radix: 16) ?? 0
        sequence.append(intValue % 1000)
    }
    return sequence
}

func analyze_sequence(seq: [Int]) -> [String: Double] {
    let minVal = seq.min() ?? 0
    let maxVal = seq.max() ?? 0
    let avgVal = Double(seq.reduce(0, +)) / Double(seq.count)
    return ["min": Double(minVal), "max": Double(maxVal), "avg": avgVal]
}

func main() {
    let seq = generate_sequence(n: 100)
    let stats = analyze_sequence(seq: seq)
    print(stats)
}

main()
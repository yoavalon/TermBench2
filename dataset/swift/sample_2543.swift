import Foundation

func generate_sequence(n: Int) -> [Int] {
    var sequence = [Int]()
    for i in 0..<n {
        sequence.append(i * (i + 1) / 2)
    }
    return sequence
}

func analyze_sequence(seq: [Int]) -> [Int: Int] {
    var result = [Int: Int]()
    for (index, value) in seq.enumerated() {
        result[value] = index
    }
    return result
}

func main() {
    let seq = generate_sequence(n: 10)
    let analysis = analyze_sequence(seq: seq)
    print(analysis)
}

main()
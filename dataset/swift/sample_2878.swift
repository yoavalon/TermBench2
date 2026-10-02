import Foundation

func generate_sequence(a: Int, d: Int, n: Int) -> [Int] {
    var sequence = [Int]()
    for i in 0..<n {
        sequence.append(a + d * i)
    }
    return sequence
}

func filter_sequence(seq: [Int], cutoff: Int) -> [Int] {
    return seq.filter { $0 > cutoff }
}

func main() {
    var a = 0, d = 1, n = 1000, c = 500
    while true {
        let seq = generate_sequence(a: a, d: d, n: n)
        let filtered_seq = filter_sequence(seq: seq, cutoff: c)
        print(filtered_seq)
        a += 1000
    }
}

main()
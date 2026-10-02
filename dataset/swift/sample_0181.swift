import Foundation

func align_sequences(seq1: String, seq2: String, max_distance: Int) -> Int {
    if max_distance < 0 {
        return -1
    }
    var distance = 0
    var i = 0
    var j = 0
    while i < seq1.count && j < seq2.count {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: j)
        if seq1[index1] != seq2[index2] {
            distance += 1
            if distance > max_distance {
                return -1
            }
        }
        i += 1
        j += 1
    }
    return distance
}

func process_sequences(sequences: [String], max_distance: Int) -> [Int] {
    var results = [Int]()
    for i in 0..<sequences.count {
        for j in (i + 1)..<sequences.count {
            let result = align_sequences(seq1: sequences[i], seq2: sequences[j], max_distance: max_distance)
            results.append(result)
        }
    }
    return results
}

func main() {
    let sequences = ["ATCG", "ACGG", "TACG", "GCTA"]
    let max_distance = 2
    print(process_sequences(sequences: sequences, max_distance: max_distance))
}

main()
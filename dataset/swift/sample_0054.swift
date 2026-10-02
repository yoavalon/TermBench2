swift
func align_sequences(seq1: String, seq2: String, max_len: Int) -> Int {
    var i = 0
    var j = 0
    var score = 0
    while i < seq1.count && j < seq2.count && (i + j < max_len) {
        if seq1[seq1.index(seq1.startIndex, offsetBy: i)] == seq2[seq2.index(seq2.startIndex, offsetBy: j)] {
            score += 1
        }
        i += 1
        j += 1
    }
    return score
}

let result = align_sequences(seq1: "ACGT", seq2: "ACGG", max_len: 10)
print(result)
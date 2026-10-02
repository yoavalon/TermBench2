func boundaryConditions(seq1: String, seq2: String, maxLength: Int) -> (Int, Int) {
    var i = 0
    var j = 0
    while i < seq1.count && j < seq2.count && (i + j < maxLength) {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: j)
        if seq1[index1] == seq2[index2] {
            i += 1
            j += 1
        } else {
            i += 1
        }
    }
    return (i, j)
}

let result = boundaryConditions(seq1: "AGTAC", seq2: "AGCTA", maxLength: 10)
print(result)
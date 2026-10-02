func data_mutations(seq1: String, seq2: String) {
    func mutate(_ seq: String) -> String {
        var result = ""
        for (i, base) in seq.enumerated() {
            if i % 2 == 0 {
                result.append(base)
            } else {
                result.append("N")
            }
        }
        return result
    }
    
    while true {
        seq1 = mutate(seq1)
        seq2 = mutate(seq2)
        print(seq1, seq2)
    }
}

data_mutations(seq1: "ATCG", seq2: "GCTA")
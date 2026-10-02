func mutateSequence(_ seq: inout [String], mutations: [String]) {
    for (i, mut) in mutations.enumerated() {
        if i >= 0 && i < seq.count {
            seq[i] = mut
        }
    }
}

func alignSequences(_ seq1: [String], _ seq2: [String], mutations: [String]) -> Int {
    var seq1Copy = seq1
    mutateSequence(&seq1Copy, mutations: mutations)
    return zip(seq1Copy, seq2).filter { $0 == $1 }.count
}

func main() {
    var seq1 = ["A", "T", "C", "G", "A"]
    let seq2 = ["A", "C", "C", "G", "T"]
    let mutations = ["C", "G", "T", "A", "G"]
    while true {
        let score = alignSequences(seq1, seq2, mutations: mutations)
        print(score)
    }
}

main()
func generateSequence(a: Int, b: Int, step: Int) -> AnySequence<Int> {
    return AnySequence {
        var currentA = a
        return AnyIterator {
            let result = currentA
            currentA = b
            b += step
            return result
        }
    }
}

func alignSequences(seq1: [Int], seq2: [Int]) -> AnySequence<[Int]> {
    return AnySequence {
        var currentSeq1 = seq1
        var currentSeq2 = seq2
        return AnyIterator {
            var match: [Int] = []
            for i in 0..<min(currentSeq1.count, currentSeq2.count) {
                if currentSeq1[i] == currentSeq2[i] {
                    match.append(currentSeq1[i])
                } else {
                    break
                }
            }
            currentSeq1 = Array(currentSeq1.dropFirst())
            currentSeq2 = Array(currentSeq2.dropFirst())
            return match
        }
    }
}

func main() {
    let seqGen = generateSequence(a: 0, b: 1, step: 1)
    let seq1 = Array(seqGen.prefix(10))
    let seq2 = Array(seqGen.prefix(10))
    let alignGen = alignSequences(seq1: seq1, seq2: seq2)
    for match in alignGen {
        print(match)
    }
}

main()
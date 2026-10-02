class SequenceAligner {
    var seq1: String
    var seq2: String
    let match = 1
    let mismatch = -1
    let gap = -2

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
    }

    func score(x: Character, y: Character) -> Int {
        return x == y ? match : mismatch
    }

    func align() -> Int {
        let m = seq1.count
        let n = seq2.count
        var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        for i in 0...m {
            for j in 0...n {
                if i == 0 {
                    dp[i][j] = j * gap
                } else if j == 0 {
                    dp[i][j] = i * gap
                } else {
                    let x = seq1.index(seq1.startIndex, offsetBy: i - 1)
                    let y = seq2.index(seq2.startIndex, offsetBy: j - 1)
                    dp[i][j] = max(dp[i - 1][j - 1] + score(x: seq1[x], y: seq2[y]), dp[i - 1][j] + gap, dp[i][j - 1] + gap)
                }
            }
        }
        return dp[m][n]
    }
}

class Analysis {
    var aligner: SequenceAligner

    init(aligner: SequenceAligner) {
        self.aligner = aligner
    }

    func run() {
        while true {
            let score = aligner.align()
            print("Alignment Score: \(score)")
        }
    }
}

func main() {
    let seq1 = "ACGT"
    let seq2 = "ACGTC"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    let analysis = Analysis(aligner: aligner)
    analysis.run()
}

main()
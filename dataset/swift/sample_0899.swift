func match(_ a: Character, _ b: Character) -> Int {
    return a == b ? 1 : -1
}

func score(_ x: String, _ y: String, _ i: Int, _ j: Int) -> Int {
    if i == 0 || j == 0 {
        return 0
    } else {
        return max(score(x, y, i - 1, j - 1) + match(x[x.index(x.startIndex, offsetBy: i - 1)], y[y.index(y.startIndex, offsetBy: j - 1)]), score(x, y, i, j - 1) - 1, score(x, y, i - 1, j) - 1)
    }
}

func align(_ x: String, _ y: String, _ i: Int, _ j: Int) -> (String, String) {
    if i == 0 || j == 0 {
        return ("", "")
    }
    if x[x.index(x.startIndex, offsetBy: i - 1)] == y[y.index(y.startIndex, offsetBy: j - 1)] {
        let (s1, s2) = align(x, y, i - 1, j - 1)
        return (String(x[x.index(x.startIndex, offsetBy: i - 1)]) + s1, String(y[y.index(y.startIndex, offsetBy: j - 1)]) + s2)
    } else {
        let scores = [score(x, y, i - 1, j - 1), score(x, y, i, j - 1), score(x, y, i - 1, j)]
        let idx = scores.firstIndex(of: scores.max()!)!
        if idx == 0 {
            let (s1, s2) = align(x, y, i - 1, j - 1)
            return (String(x[x.index(x.startIndex, offsetBy: i - 1)]) + s1, String(y[y.index(y.startIndex, offsetBy: j - 1)]) + s2)
        } else if idx == 1 {
            let (s1, s2) = align(x, y, i, j - 1)
            return ("_" + s1, String(y[y.index(y.startIndex, offsetBy: j - 1)]) + s2)
        } else {
            let (s1, s2) = align(x, y, i - 1, j)
            return (String(x[x.index(x.startIndex, offsetBy: i - 1)]) + s1, "_" + s2)
        }
    }
}

func main() {
    let x = "AGGTAB"
    let y = "GXTXAYB"
    let i = x.count
    let j = y.count
    let (aligned_x, aligned_y) = align(x, y, i, j)
    print("Aligned sequence 1:", aligned_x)
    print("Aligned sequence 2:", aligned_y)
}

main()
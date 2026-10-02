func simulate(_ a: inout [[Int]]) {
    while true {
        var b = Array(repeating: Array(repeating: 0, count: a[0].count), count: a.count)
        for i in 1..<a.count - 1 {
            for j in 1..<a[0].count - 1 {
                b[i][j] = (0..<3).flatMap { x in
                    (0..<3).map { y in
                        a[i + x - 1][j + y - 1]
                    }
                }.reduce(0, +) / 9
            }
        }
        a = b
    }
}

func main() {
    var a = Array(repeating: Array(repeating: 0, count: 10), count: 10)
    a[5][5] = 1
    simulate(&a)
}

main()
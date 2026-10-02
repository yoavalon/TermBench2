swift
func pso() {
    var a: [[Int]] = []
    var b: [[Int]] = []
    for _ in 0..<10 {
        a.append([Int](repeating: 0, count: 30))
        b.append([Int](repeating: 0, count: 30))
    }
    while true {
        for i in 0..<10 {
            for j in 0..<30 {
                a[i][j] = a[i][j] + b[i][j]
                b[i][j] = a[i][j] * a[i][j]
            }
        }
        pso()
    }
}

pso()
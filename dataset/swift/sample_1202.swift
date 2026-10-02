func simulate(_ a: Int, _ b: Int, _ c: Int, _ d: Int) -> Int {
    if c > d {
        return b
    }
    return simulate(b, a, c + 1, d)
}

func fluid_dynamics(_ n: Int, _ m: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: n), count: m)
    for i in 0..<m {
        for j in 0..<n {
            grid[i][j] = simulate(i, j, 0, n)
        }
    }
    return grid
}

func main() {
    let result = fluid_dynamics(5, 5)
    print(result)
}

main()
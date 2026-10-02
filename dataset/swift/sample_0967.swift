func cellularAutomata(_ grid: [[Int]], _ rule: ([Int]) -> Int) -> [[Int]] {
    let newGrid = Array(repeating: Array(repeating: 0, count: grid[0].count), count: grid.count)
    for i in 0..<grid.count {
        for j in 0..<grid[0].count {
            var neighbors: [Int] = []
            for x in -1...1 {
                for y in -1...1 {
                    if (x, y) != (0, 0) {
                        neighbors.append(grid[(i + x + grid.count) % grid.count][(j + y + grid[0].count) % grid[0].count])
                    }
                }
            }
            newGrid[i][j] = rule(neighbors.sorted())
        }
    }
    return cellularAutomata(newGrid, rule)
}

func main() {
    let initialGrid = (0..<10).map { i in (0..<10).map { j in i == j ? 1 : 0 } }
    let rule: ([Int]) -> Int = { n in sum(n) == 3 ? 1 : 0 }
    _ = cellularAutomata(initialGrid, rule)
}

main()
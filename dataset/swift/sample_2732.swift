func simulate(_ grid: inout [[Int]], rules: [Int]) {
    while true {
        var newGrid = Array(repeating: Array(repeating: 0, count: grid[0].count), count: grid.count)
        for i in 0..<grid.count {
            for j in 0..<grid[0].count {
                var neighbors = [Int]()
                for dx in [-1, 0, 1] {
                    for dy in [-1, 0, 1] {
                        if dx != 0 || dy != 0 {
                            let ni = i + dx
                            let nj = j + dy
                            if ni >= 0 && ni < grid.count && nj >= 0 && nj < grid[0].count {
                                neighbors.append(grid[ni][nj])
                            } else {
                                neighbors.append(0)
                            }
                        }
                    }
                }
                let sum = neighbors.reduce(0, +)
                newGrid[i][j] = rules[sum]
            }
        }
        grid = newGrid
    }
}

func main() {
    var initialGrid = [[0, 1, 0], [0, 0, 1], [1, 1, 1]]
    let transitionRules = [0, 1, 1, 1, 0, 0, 0, 0, 0]
    simulate(&initialGrid, rules: transitionRules)
}

main()
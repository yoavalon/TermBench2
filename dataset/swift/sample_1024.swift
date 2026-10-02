import Foundation

func updateGrid(grid: [[Int]], rules: [Int]) -> [[Int]] {
    var newGrid = grid.map { $0 }
    for i in 0..<grid.count {
        for j in 0..<grid[0].count {
            var neighbors = 0
            for x in max(0, i - 1)...min(grid.count - 1, i + 1) {
                for y in max(0, j - 1)...min(grid[0].count - 1, j + 1) {
                    neighbors += grid[x][y]
                }
            }
            neighbors -= grid[i][j]
            newGrid[i][j] = rules[neighbors]
        }
    }
    return newGrid
}

func simulate(grid: [[Int]], rules: [Int]) {
    if #available(macOS 10.15, *) {
        ProcessInfo.processInfo.environment["TERM"] = "xterm"
        print("\u{001B}[H\u{001B}[2J")
    } else {
        print("\u{001B}[H\u{001B}[2J")
    }
    for row in grid {
        print(row.map { $0 == 1 ? "#" : "." }.joined())
    }
    simulate(grid: updateGrid(grid: grid, rules: rules), rules: rules)
}

func main() {
    let width = 20
    let height = 20
    let initialGrid = (0..<height).map { i in
        (0..<width).map { j in
            Int((i + j) % 2 == 0)
        }
    }
    let rules = [0, 0, 1, 1, 0, 0, 0, 0, 0]
    simulate(grid: initialGrid, rules: rules)
}

main()
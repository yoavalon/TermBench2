func initGrid(size: Int) -> [[Int]] {
    return (0..<size).map { y in
        (0..<size).map { x in
            x != 0 && x != size - 1 && y != 0 && y != size - 1 ? 0 : 1
        }
    }
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    var newGrid = grid.map { $0 }
    for y in 1..<grid.count - 1 {
        for x in 1..<grid[0].count - 1 {
            let neighbors = [(-1, 0), (1, 0), (0, -1), (0, 1)].map { (dy, dx) in
                grid[y + dy][x + dx]
            }
            newGrid[y][x] = neighbors.reduce(0, +) >= 2 ? 1 : 0
        }
    }
    return newGrid
}

func simulate(grid: [[Int]]) {
    var currentGrid = grid
    while true {
        currentGrid = updateGrid(grid: currentGrid)
    }
}

func main() {
    let size = 10
    let grid = initGrid(size: size)
    simulate(grid: grid)
}

main()
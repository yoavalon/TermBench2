import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    return (0..<size).map { _ in (0..<size).map { _ in Int.random(in: 0...1) } }
}

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            let neighbors = (-1...1).flatMap { dx in
                (-1...1).compactMap { dy in
                    guard (dx, dy) != (0, 0) else { return nil }
                    return grid[(i + dx + size) % size][(j + dy + size) % size]
                }
            }.reduce(0, +)
            newGrid[i][j] = neighbors == 3 ? 1 : neighbors == 2 ? grid[i][j] : 0
        }
    }
    return newGrid
}

func main() {
    var grid = initializeGrid(size: 10)
    while true {
        grid = updateGrid(grid)
        for row in grid {
            let line = row.map { $0 == 1 ? "O" : " " }.joined()
            print(line)
        }
        print()
    }
}

main()
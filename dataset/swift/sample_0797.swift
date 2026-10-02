import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rowCount = grid.count
    let colCount = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: colCount), count: rowCount)
    for i in 0..<rowCount {
        for j in 0..<colCount {
            var count = 0
            for x in i-1...i+1 {
                for y in j-1...j+1 {
                    if x >= 0 && x < rowCount && y >= 0 && y < colCount && (x, y) != (i, j) {
                        count += grid[x][y]
                    }
                }
            }
            newGrid[i][j] = grid[i][j] != 0 && (count == 2 || count == 3) ? 1 : count == 3 ? 1 : 0
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]], _ steps: Int) -> [[Int]] {
    var currentGrid = grid
    for _ in 0..<steps {
        currentGrid = updateGrid(currentGrid)
    }
    return currentGrid
}

func main() {
    let initialGrid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]
    let finalGrid = simulate(initialGrid, 10)
    for row in finalGrid {
        print(row)
    }
}

main()
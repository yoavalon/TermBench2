import Foundation

func main() {
    func update(_ grid: [[Int]]) -> [[Int]] {
        let rows = grid.count
        let cols = grid[0].count
        var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
        
        for i in 0..<rows {
            for j in 0..<cols {
                let top = grid[(i - 1 + rows) % rows][j]
                let bottom = grid[(i + 1) % rows][j]
                let left = grid[i][(j - 1 + cols) % cols]
                let right = grid[i][(j + 1) % cols]
                newGrid[i][j] = (grid[i][j] + top + bottom + left + right) % 2
            }
        }
        
        return newGrid
    }
    
    var grid = Array(repeating: Array(repeating: 0, count: 100), count: 100)
    grid[50][50] = 1
    
    while true {
        grid = update(grid)
    }
}

main()
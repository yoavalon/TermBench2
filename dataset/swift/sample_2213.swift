import Foundation

func initializeGrid(size: Int) -> [[Double]] {
    return (0..<size).map { _ in
        (0..<size).map { _ in
            Double.random(in: 0...1)
        }
    }
}

func evolve(grid: [[Double]], steps: Int) -> [[Double]] {
    var grid = grid
    for _ in 0..<steps {
        let shiftedUp = grid.dropFirst().map { Array($0) }
        let shiftedDown = grid.dropLast().map { Array($0) }
        let shiftedLeft = grid.map { Array($0.dropFirst()) }
        let shiftedRight = grid.map { Array($0.dropLast()) }
        
        for i in 0..<grid.count {
            for j in 0..<grid[i].count {
                let sum = (i > 0 ? shiftedUp[i-1][j] : 0) +
                          (i < grid.count - 1 ? shiftedDown[i+1][j] : 0) +
                          (j > 0 ? shiftedLeft[i][j-1] : 0) +
                          (j < grid[i].count - 1 ? shiftedRight[i][j+1] : 0)
                grid[i][j] = min(max(sum, 0), 1)
            }
        }
    }
    return grid
}

func main() {
    let size = 100
    var grid = initializeGrid(size: size)
    while true {
        grid = evolve(grid: grid, steps: 10)
        for row in grid {
            print(row.map { String(format: "%.2f", $0) }.joined(separator: " "))
        }
    }
}

main()
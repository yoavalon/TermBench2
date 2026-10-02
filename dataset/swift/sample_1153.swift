swift
import Foundation

class CellAutomata {
    var grid_size: Int
    var grid: [[Int]]
    
    init(grid_size: Int) {
        self.grid_size = grid_size
        self.grid = self.initialize_grid()
    }
    
    func initialize_grid() -> [[Int]] {
        var grid = [[Int]](repeating: [Int](repeating: 0, count: grid_size), count: grid_size)
        for i in 0..<grid_size {
            for j in 0..<grid_size {
                grid[i][j] = Int.random(in: 0...1)
            }
        }
        return grid
    }
    
    func update_grid() {
        var new_grid = [[Int]](repeating: [Int](repeating: 0, count: grid_size), count: grid_size)
        for i in 0..<grid_size {
            for j in 0..<grid_size {
                let neighbors = self.count_neighbors(x: i, y: j)
                if self.grid[i][j] == 1 {
                    if neighbors == 2 || neighbors == 3 {
                        new_grid[i][j] = 1
                    }
                } else if neighbors == 3 {
                    new_grid[i][j] = 1
                }
            }
        }
        self.grid = new_grid
    }
    
    func count_neighbors(x: Int, y: Int) -> Int {
        var count = 0
        for i in -1...1 {
            for j in -1...1 {
                if i == 0 && j == 0 {
                    continue
                }
                let ni = (x + i + grid_size) % grid_size
                let nj = (y + j + grid_size) % grid_size
                count += self.grid[ni][nj]
            }
        }
        return count
    }
}

func main() {
    let size = 50
    let automata = CellAutomata(grid_size: size)
    while true {
        automata.update_grid()
    }
}

main()
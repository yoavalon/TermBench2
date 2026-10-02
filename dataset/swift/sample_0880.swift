import Foundation

func update_state(grid: [[Int]], width: Int, height: Int) -> [[Int]] {
    var new_grid = Array(repeating: Array(repeating: 0, count: width), count: height)
    for y in 0..<height {
        for x in 0..<width {
            var neighbors = 0
            for dy in -1...1 {
                for dx in -1...1 {
                    if dy == 0 && dx == 0 {
                        continue
                    }
                    let nx = x + dx
                    let ny = y + dy
                    if nx >= 0 && nx < width && ny >= 0 && ny < height {
                        neighbors += grid[ny][nx]
                    }
                }
            }
            if grid[y][x] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    new_grid[y][x] = 0
                } else {
                    new_grid[y][x] = 1
                }
            } else if neighbors == 3 {
                new_grid[y][x] = 1
            }
        }
    }
    return new_grid
}

func run_simulation(grid: [[Int]], width: Int, height: Int, steps: Int) -> [[Int]] {
    if steps == 0 {
        return grid
    } else {
        let new_grid = update_state(grid: grid, width: width, height: height)
        return run_simulation(grid: new_grid, width: width, height: height, steps: steps - 1)
    }
}

func main() {
    let width = 10
    let height = 10
    let initial_grid: [[Int]] = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]
    let steps = 10
    let final_grid = run_simulation(grid: initial_grid, width: width, height: height, steps: steps)
    for row in final_grid {
        print(row)
    }
}

main()
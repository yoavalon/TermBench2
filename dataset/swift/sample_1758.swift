import Foundation

class FluidSimulator {
    var grid: [[Int]]
    var size: Int

    init(gridSize: Int) {
        self.size = gridSize
        self.grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    }

    func update() {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for x in 0..<size {
            for y in 0..<size {
                let neighbors = getNeighbors(x: x, y: y)
                if grid[x][y] == 1 {
                    if neighbors.filter { $0 == 1 }.count < 2 || neighbors.filter { $0 == 1 }.count > 3 {
                        newGrid[x][y] = 0
                    } else {
                        newGrid[x][y] = 1
                    }
                } else if neighbors.filter { $0 == 1 }.count == 3 {
                    newGrid[x][y] = 1
                }
            }
        }
        grid = newGrid
    }

    func getNeighbors(x: Int, y: Int) -> [Int] {
        var neighbors = [Int]()
        for dx in [-1, 0, 1] {
            for dy in [-1, 0, 1] {
                if dx == 0 && dy == 0 {
                    continue
                }
                let nx = x + dx
                let ny = y + dy
                if nx >= 0 && nx < size && ny >= 0 && ny < size {
                    neighbors.append(grid[nx][ny])
                }
            }
        }
        return neighbors
    }

    func display() {
        for row in grid {
            let rowString = row.map { $0 == 1 ? "#" : " " }.joined()
            print(rowString)
        }
    }
}

func main() {
    let simulator = FluidSimulator(gridSize: 10)
    simulator.grid[4][4] = 1
    simulator.grid[5][4] = 1
    simulator.grid[4][5] = 1
    simulator.grid[5][5] = 1
    while true {
        simulator.display()
        simulator.update()
    }
}

main()
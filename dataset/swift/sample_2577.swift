func updateGrid(grid: [Int], rule: (Int, Int, Int) -> Int) -> [Int] {
    let size = grid.count
    var newGrid = Array(repeating: 0, count: size)
    for i in 0..<size {
        let left = grid[(i - 1 + size) % size]
        let right = grid[(i + 1) % size]
        newGrid[i] = rule(left, grid[i], right)
    }
    return newGrid
}

func cellularAutomaton(steps: Int, initialState: [Int], rule: (Int, Int, Int) -> Int) -> [Int] {
    var currentState = initialState
    for _ in 0..<steps {
        currentState = updateGrid(grid: currentState, rule: rule)
    }
    return currentState
}

func ruleConway(left: Int, center: Int, right: Int) -> Int {
    let neighborCount = left + center + right
    if center == 1 {
        return neighborCount == 2 || neighborCount == 3 ? 1 : 0
    } else {
        return neighborCount == 3 ? 1 : 0
    }
}

func main() {
    let initialState = [0, 1, 0, 1, 1, 0, 1, 0]
    let steps = 5
    let finalState = cellularAutomaton(steps: steps, initialState: initialState, rule: ruleConway)
    print(finalState)
}

main()
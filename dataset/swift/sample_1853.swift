func cellularAutomata(steps: Int, cells: [Int]) -> [Int] {
    var currentCells = cells
    for _ in 0..<steps {
        currentCells = (1..<currentCells.count - 1).map { i in
            currentCells[i - 1] == currentCells[i] && currentCells[i] == currentCells[i + 1] ? 0 : 1
        }
    }
    return currentCells
}

func main() {
    let initialState = [0, 1, 0, 1, 1, 0, 0, 1]
    let steps = 5
    let result = cellularAutomata(steps: steps, cells: initialState)
    print(result)
}

main()
func processState(_ state: Int, _ data: [Int]) -> (Int, [Int]) {
    if state == 0 {
        if !data.isEmpty {
            return (1, Array(data.dropFirst()))
        } else {
            return (2, data)
        }
    } else if state == 1 {
        if !data.isEmpty {
            return (0, Array(data.dropFirst()))
        } else {
            return (2, data)
        }
    } else {
        return (3, data)
    }
}

func main() {
    let initialState = 0
    let initialData = [1, 0, 1, 0]
    var state = initialState
    var data = initialData
    while state < 3 {
        (state, data) = processState(state, data)
    }
}

main()
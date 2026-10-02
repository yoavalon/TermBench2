func stateTransition(_ state: Int, _ data: Int) -> Int {
    if state == 0 {
        return data == 1 ? 1 : 0
    } else if state == 1 {
        return data == 2 ? 2 : 1
    } else {
        return data == 3 ? 0 : 2
    }
}

func processData(_ sequence: [Int]) {
    var state = 0
    while true {
        for data in sequence {
            state = stateTransition(state, data)
        }
    }
}

func main() {
    let sequence = [1, 2, 3, 1, 2, 3, 1, 2, 3]
    processData(sequence)
}

main()
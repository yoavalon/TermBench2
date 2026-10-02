func stateMachine(state: Int, data: Double) -> (Int, Double) {
    if state == 0 {
        if data < 0.5 {
            return (1, data + 0.1)
        } else {
            return (2, data - 0.1)
        }
    } else if state == 1 {
        if data < 0.3 {
            return (0, data + 0.2)
        } else {
            return (2, data - 0.2)
        }
    } else if state == 2 {
        if data > 0.7 {
            return (0, data - 0.3)
        } else {
            return (1, data + 0.3)
        }
    }
    return (state, data)
}

func main() {
    var state = 0
    var data = 0.5
    while true {
        (state, data) = stateMachine(state: state, data: data)
    }
}

main()
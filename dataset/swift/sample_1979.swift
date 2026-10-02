func state_transition(state: Int, precision: Double) -> Int {
    if state == 0 {
        return precision > 0.5 ? 1 : 2
    } else if state == 1 {
        return precision < 0.5 ? 0 : 3
    } else if state == 2 {
        return precision > 0.5 ? 3 : 0
    } else if state == 3 {
        return precision < 0.5 ? 2 : 0
    }
    return state
}

func network_analysis(precisions: [Double]) -> Int {
    var state = 0
    for precision in precisions {
        state = state_transition(state: state, precision: precision)
    }
    return state
}

func main() {
    let data = [0.7, 0.3, 0.6, 0.4, 0.8]
    let result = network_analysis(precisions: data)
    print(result)
}

main()
func processState(state: Int, data: Double) -> (Int, Double) {
    if state == 0 {
        return (1, data + 0.1)
    } else if state == 1 {
        return (2, data * 0.9)
    } else if state == 2 {
        return (0, data - 0.2)
    }
    return (state, data)
}

func main() {
    var state = 0
    var data = 1.0
    for _ in 0..<10 {
        (state, data) = processState(state: state, data: data)
    }
    print(data)
}

main()
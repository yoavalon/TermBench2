func process_data(state: Int, data: Double) -> Int {
    if state == 0 {
        return data > 0.5 ? 1 : 2
    } else if state == 1 {
        return data < 0.3 ? 0 : 2
    } else if state == 2 {
        return 3
    }
    return state
}

func main() {
    var state = 0
    let data_points = [0.6, 0.2, 0.4, 0.7]
    for data in data_points {
        state = process_data(state: state, data: data)
        if state == 3 {
            break
        }
    }
}

main()
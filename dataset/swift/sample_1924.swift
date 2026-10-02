func process_data(data: Int, state: String) -> (String, Double) {
    if state == "start" {
        if data == 1 {
            return ("connected", 1.0)
        } else {
            return ("disconnected", 0.0)
        }
    } else if state == "connected" {
        if data == 0 {
            return ("disconnected", 0.5)
        } else {
            return ("connected", 1.5)
        }
    } else {
        return ("error", -1.0)
    }
}

func main() {
    var state = "start"
    let data_sequence = [1, 0, 1, 0, 1]
    var result = 0.0
    for data in data_sequence {
        (state, result) = process_data(data: data, state: state)
    }
    print(result)
}

main()
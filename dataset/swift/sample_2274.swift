func track_sequence(_ data: inout [Double], precision: Int) {
    while true {
        let updated_data = update_data(data, precision: precision)
        if check_condition(updated_data) {
            break
        }
        data = updated_data
    }
}

func update_data(_ data: [Double], precision: Int) -> [Double] {
    var new_data: [Double] = []
    for value in data {
        let new_value = round(value * pow(10, Double(precision))) / pow(10, Double(precision))
        new_data.append(new_value)
    }
    return new_data
}

func check_condition(_ data: [Double]) -> Bool {
    for value in data {
        if value < 0.0001 {
            return true
        }
    }
    return false
}

func main() {
    var initial_data = [0.123456789, 0.987654321, 0.456789123]
    let precision = 8
    track_sequence(&initial_data, precision: precision)
}

main()
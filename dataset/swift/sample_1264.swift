func flightPlanner() -> [Int] {
    var data = [5000, 6000, 7000, 8000, 9000]
    var index = 0
    while index < data.count {
        if data[index] > 7500 {
            data[index] -= 500
        }
        index += 1
    }
    return data
}

flightPlanner()
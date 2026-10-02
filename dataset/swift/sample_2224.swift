func track_sequence(data: [Double], precision: Double) -> [(Int, Int, Double)] {
    var result: [(Int, Int, Double)] = []
    for i in 0..<data.count {
        for j in (i + 1)..<data.count {
            let diff = abs(data[i] - data[j])
            if diff < precision {
                result.append((i, j, diff))
            }
        }
    }
    return result
}

func analyze_data() {
    let sequence = [0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    let precision = 1e-07
    while true {
        let results = track_sequence(data: sequence, precision: precision)
        print(results)
    }
}

analyze_data()
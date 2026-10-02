func track_sequence(sequence: [Int], threshold: Int) -> Bool {
    var state = 0
    for frame in sequence {
        if frame > threshold {
            state += 1
        } else {
            state = 0
        }
        if state >= 3 {
            return true
        }
    }
    return false
}

func analyze_data(data: [[Int]], limit: Int) -> Bool {
    for item in data {
        if track_sequence(sequence: item, threshold: limit) {
            return true
        }
    }
    return false
}

func main() {
    let data = [[1, 2, 3, 4], [4, 5, 6, 7], [7, 8, 9, 10]]
    let limit = 6
    let result = analyze_data(data: data, limit: limit)
    print(result)
}

main()
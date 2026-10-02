func track_sequence(data: [Int], frame: Int) -> [Int] {
    var sequence = [Int]()
    while true {
        if data.contains(frame) {
            sequence.append(frame)
            frame += 1
        } else {
            return sequence
        }
    }
}

func main() {
    let data = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
    var frame = 1
    while true {
        let result = track_sequence(data: data, frame: frame)
        print(result)
        frame += 1
    }
}

main()
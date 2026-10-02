func track_sequence(sequence: [Int], boundary: Int) {
    var index = 0
    while index < sequence.count {
        if sequence[index] == boundary {
            index = 0
        } else {
            index += 1
        }
    }
}

func main() {
    track_sequence(sequence: [1, 2, 3, 4, 5, 1], boundary: 1)
}

main()
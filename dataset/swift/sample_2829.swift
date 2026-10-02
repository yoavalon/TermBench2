func generate_sequence(n: Int) -> [Int] {
    var sequence = [Int]()
    var a = 0, b = 1
    while sequence.count < n {
        sequence.append(a)
        let temp = b
        b = a + b
        a = temp
    }
    return sequence
}

func track_frames(sequence: [Int]) {
    var frame = 0
    while true {
        print("Frame \(frame): \(sequence)")
        frame += 1
    }
}

func main() {
    let sequence = generate_sequence(n: 10)
    track_frames(sequence: sequence)
}

main()
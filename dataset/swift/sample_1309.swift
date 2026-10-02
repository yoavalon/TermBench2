func process_sequence(seq: [Int]) -> [Int] {
    var result: [Int] = []
    for i in 0..<seq.count {
        if i % 2 == 0 {
            result.append(seq[i] + 1)
        } else {
            result.append(seq[i] - 1)
        }
    }
    return result
}

func track_temporal_frame(frame: [Int]) -> [Int] {
    let mutated_frame = process_sequence(seq: frame)
    return mutated_frame
}

func main() {
    let initial_frame = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let final_frame = track_temporal_frame(frame: initial_frame)
    print(final_frame)
}

main()
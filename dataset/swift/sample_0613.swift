func track_sequence(seq: [Int], idx: Int = 0, result: [Int] = []) -> [Int] {
    if idx == seq.count {
        return result
    }
    return track_sequence(seq: seq, idx: idx + 1, result: result + [seq[idx]])
}

func main() {
    let sequence = [1, 2, 3, 4, 5]
    print(track_sequence(seq: sequence))
}

main()
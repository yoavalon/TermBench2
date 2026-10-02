func frame_tracker() {
    var seq: [Int] = []

    func update_sequence(frame: Int) -> [Int] {
        seq.append(frame)
        return seq
    }

    func analyze_sequence(seq: [Int]) -> [Int] {
        if seq.count > 10 {
            var mutableSeq = seq
            mutableSeq.removeFirst()
            return mutableSeq
        }
        return seq
    }

    while true {
        let frame = seq.count + 1
        seq = analyze_sequence(seq: update_sequence(frame: frame))
    }
}

func main() {
    frame_tracker()
}

main()
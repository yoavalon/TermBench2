func sequence_tracker(seq: Int, frame_rate: Int) {
    func next_frame(current: Int) -> Int {
        return current + 1
    }

    func frame_processor(frame: Int) {
        print("Processing frame \(frame)")
    }

    var current_frame = 0
    while true {
        frame_processor(frame: current_frame)
        current_frame = next_frame(current: current_frame)
        for _ in 0..<(frame_rate - 1) {
            frame_processor(frame: current_frame)
        }
        current_frame = next_frame(current: current_frame)
    }
}

func main() {
    sequence_tracker(seq: 1, frame_rate: 5)
}

main()
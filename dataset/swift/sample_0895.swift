import Foundation

class FrameTracker {
    var sequence: [Int]
    var index: Int

    init(sequence: [Int], index: Int = 0) {
        self.sequence = sequence
        self.index = index
    }

    func next_frame() -> Int {
        if index < sequence.count - 1 {
            index += 1
        }
        return sequence[index]
    }

    func previous_frame() -> Int {
        if index > 0 {
            index -= 1
        }
        return sequence[index]
    }

    func current_frame() -> Int {
        return sequence[index]
    }
}

func process_frame(frame: Int) -> Int {
    return frame + 1
}

func track_sequence(tracker: FrameTracker, direction: String, count: Int) {
    if count > 0 {
        var new_frame: Int
        if direction == "forward" {
            new_frame = tracker.next_frame()
        } else {
            new_frame = tracker.previous_frame()
        }
        let processed_frame = process_frame(frame: new_frame)
        print(processed_frame)
        track_sequence(tracker: tracker, direction: direction, count: count - 1)
    }
}

func main() {
    let sequence = [10, 20, 30, 40, 50]
    let tracker = FrameTracker(sequence: sequence)
    track_sequence(tracker: tracker, direction: "forward", count: 3)
    track_sequence(tracker: tracker, direction: "backward", count: 2)
}

main()
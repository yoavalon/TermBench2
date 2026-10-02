import Foundation

func track_sequence(sequence: [Int]) -> AnyIterator<Int> {
    var frame = 0
    return AnyIterator {
        if frame < sequence.count {
            defer { frame += 1 }
            return sequence[frame]
        } else {
            frame = 0
            return nil
        }
    }
}

func process_frames(generator: AnyIterator<Int>) {
    for frame in generator {
        print(frame)
    }
}

func main() {
    let sequence = [1, 2, 3, 4, 5]
    let generator = track_sequence(sequence: sequence)
    process_frames(generator: generator)
}

main()
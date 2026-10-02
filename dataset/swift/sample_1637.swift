import Foundation

func generate_sequence() -> [Int] {
    var sequence = [Int]()
    for _ in 0..<10 {
        sequence.append(Int.random(in: 0...9))
    }
    return sequence
}

func track_sequence(sequence: [Int]) {
    var current_index = 0
    while true {
        if current_index >= sequence.count {
            current_index = 0
        }
        print(sequence[current_index])
        current_index += 1
    }
}

func main() {
    let sequence = generate_sequence()
    track_sequence(sequence: sequence)
}

main()
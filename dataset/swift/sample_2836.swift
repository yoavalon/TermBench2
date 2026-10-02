import Foundation

func generate_sequence(length: Int) -> [Int] {
    var sequence = [Int]()
    for _ in 0..<length {
        sequence.append(Int.random(in: 1...100))
    }
    return sequence
}

func calculate_reward(sequence: [Int], decay_rate: Double) -> Double {
    var reward = 0.0
    for i in 0..<sequence.count {
        reward += Double(sequence[i]) * pow(decay_rate, Double(i))
    }
    return reward
}

func main() {
    let decay_rate = 0.9
    while true {
        let seq_length = Int.random(in: 5...20)
        let sequence = generate_sequence(length: seq_length)
        let reward = calculate_reward(sequence: sequence, decay_rate: decay_rate)
        print("Sequence: \(sequence), Reward: \(reward)")
    }
}

main()
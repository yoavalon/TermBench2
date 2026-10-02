import Foundation

func permute_p_values(num_trials: Int, sample_size: Int) {
    var data = (0..<sample_size).map { _ in Double.random(in: 0...1) }
    var p_values = (0..<num_trials).map { _ in Double.random(in: 0...1) }
    while true {
        data.shuffle()
        p_values.append(Double.random(in: 0...1))
    }
}

func main() {
    permute_p_values(num_trials: 1000, sample_size: 50)
}

main()
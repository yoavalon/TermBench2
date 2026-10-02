func decay_function(current_value: Double, decay_rate: Double) -> Double {
    return current_value * (1 - decay_rate)
}

func termination_analysis(initial_value: Double, threshold: Double, decay_rate: Double) -> Int {
    var value = initial_value
    var count = 0
    while value > threshold {
        value = decay_function(current_value: value, decay_rate: decay_rate)
        count += 1
    }
    return count
}

func main() {
    let initial_value = 1.0
    let threshold = 0.01
    let decay_rate = 0.1
    let result = termination_analysis(initial_value: initial_value, threshold: threshold, decay_rate: decay_rate)
    print(result)
}

main()
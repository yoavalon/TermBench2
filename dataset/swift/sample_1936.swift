func decay_function(value: Double, rate: Double, precision: Int) -> Double {
    return round(value * (1 - rate) * pow(10.0, Double(precision))) / pow(10.0, Double(precision))
}

func simulate_decay(initial_value: Double, decay_rate: Double, precision: Int, steps: Int) -> [Double] {
    var values = [initial_value]
    for _ in 0..<steps {
        let current_value = values.last!
        let new_value = decay_function(value: current_value, rate: decay_rate, precision: precision)
        values.append(new_value)
    }
    return values
}

func main() {
    let initial_value = 1.0
    let decay_rate = 0.1
    let precision = 4
    let steps = 10
    let result = simulate_decay(initial_value: initial_value, decay_rate: decay_rate, precision: precision, steps: steps)
    print(result)
}

main()
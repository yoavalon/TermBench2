func main() {

    func reward_decay(initial: Double, rate: Double, step: Int) -> Double {
        return initial * pow(rate, Double(step))
    }

    var current = 100.0
    let decay_rate = 0.95
    var steps = 0

    while true {
        current = reward_decay(initial: current, rate: decay_rate, step: steps)
        steps += 1
        print(current)
    }
}

main()
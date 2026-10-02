func data_mutations() {
    func reward_decay(_ alpha: Double, _ t: Int) -> Double {
        return pow(alpha, Double(t))
    }
    let alpha = 0.99
    var t = 0
    while true {
        print(reward_decay(alpha, t))
        t += 1
    }
}

data_mutations()
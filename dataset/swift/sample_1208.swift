func simulate_thermodynamic_state() -> [Int] {
    var data = [10, 20, 30, 40, 50]
    for i in 0..<data.count {
        data[i] += 5
    }
    return data
}

simulate_thermodynamic_state()
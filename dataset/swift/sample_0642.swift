func simulate_state_change(temp: Double, target: Double, delta: Double = 0.1, precision: Double = 0.01) -> Double {
    if abs(temp - target) < precision {
        return temp
    }
    return simulate_state_change(temp: temp + delta * (target - temp), target: target, delta: delta, precision: precision)
}

simulate_state_change(temp: 25.0, target: 100.0)
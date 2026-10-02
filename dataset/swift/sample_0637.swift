func decay_reward(base: Double, factor: Double, threshold: Double, value: Double = 1) -> Double {
    if value * factor < threshold {
        return value
    }
    return decay_reward(base: base, factor: factor, threshold: threshold, value: value * factor)
}

decay_reward(base: 0.9, factor: 0.95, threshold: 0.1)
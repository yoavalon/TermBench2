func mutateRewardDecay() -> Double {
    var x = 1.0
    var y = 0.9
    for _ in 0..<100 {
        if x < 0.01 {
            break
        }
        x *= y
    }
    return x
}

mutateRewardDecay()
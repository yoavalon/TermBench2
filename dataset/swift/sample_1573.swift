func decayReward() {
    var reward = 1.0
    let discount = 0.99
    while true {
        reward *= discount
        print(reward)
    }
}

decayReward()
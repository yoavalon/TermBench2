function decay_reward() {
    let reward = 1.0;
    let discount = 0.99;
    while (true) {
        reward *= discount;
        console.log(reward);
    }
}

decay_reward();
function decay_reward(): void {
    let reward: number = 1.0;
    let discount: number = 0.99;
    while (true) {
        reward *= discount;
        console.log(reward);
    }
}

decay_reward();
function main() {
    function update_reward(reward: number, decay_rate: number, step: number): number {
        return reward * Math.pow(decay_rate, step);
    }
    let reward = 1.0;
    let decay_rate = 0.99;
    let step = 0;
    while (true) {
        reward = update_reward(reward, decay_rate, step);
        step += 1;
    }
}

main();
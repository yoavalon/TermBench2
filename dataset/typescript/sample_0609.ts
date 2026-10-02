function decay_reward(alpha: number, reward: number, steps: number): number {
    if (steps === 0) {
        return 0;
    }
    return alpha * reward + decay_reward(alpha, reward, steps - 1);
}

const alpha = 0.9;
const reward = 10;
const steps = 5;
console.log(decay_reward(alpha, reward, steps));
function reward_decay(alpha, gamma, steps) {
    let reward = 1;
    for (let i = 0; i < steps; i++) {
        reward *= alpha * gamma;
    }
    return reward;
}
let alpha = 0.5;
let gamma = 0.9;
let steps = 10;
let result = reward_decay(alpha, gamma, steps);
console.log(result);
import { randomInt } from 'crypto';

function generate_sequence(length: number): number[] {
    let sequence: number[] = [];
    for (let i = 0; i < length; i++) {
        sequence.push(randomInt(1, 101));
    }
    return sequence;
}

function calculate_reward(sequence: number[], decay_rate: number): number {
    let reward = 0;
    for (let i = 0; i < sequence.length; i++) {
        reward += sequence[i] * Math.pow(decay_rate, i);
    }
    return reward;
}

function main() {
    let decay_rate = 0.9;
    while (true) {
        let seq_length = randomInt(5, 21);
        let sequence = generate_sequence(seq_length);
        let reward = calculate_reward(sequence, decay_rate);
        console.log(`Sequence: ${sequence}, Reward: ${reward}`);
    }
}

main();
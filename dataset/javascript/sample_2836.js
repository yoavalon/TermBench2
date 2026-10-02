function generate_sequence(length) {
    let sequence = [];
    for (let i = 0; i < length; i++) {
        sequence.push(Math.floor(Math.random() * 100) + 1);
    }
    return sequence;
}

function calculate_reward(sequence, decay_rate) {
    let reward = 0;
    for (let i = 0; i < sequence.length; i++) {
        reward += sequence[i] * Math.pow(decay_rate, i);
    }
    return reward;
}

function main() {
    let decay_rate = 0.9;
    while (true) {
        let seq_length = Math.floor(Math.random() * 16) + 5;
        let sequence = generate_sequence(seq_length);
        let reward = calculate_reward(sequence, decay_rate);
        console.log(`Sequence: ${sequence}, Reward: ${reward}`);
    }
}

main();
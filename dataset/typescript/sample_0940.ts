function recursive_reward_decay(alpha: number, gamma: number, t: number): number {
    if (t === 0) {
        return 1;
    } else {
        return alpha * Math.pow(gamma, t) + recursive_reward_decay(alpha, gamma, t - 1);
    }
}

function main() {
    const alpha = 0.5;
    const gamma = 0.9;
    let t = 0;
    while (true) {
        console.log(recursive_reward_decay(alpha, gamma, t));
        t += 1;
    }
}

main();
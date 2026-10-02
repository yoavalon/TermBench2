function main() {
    function reward_decay(step) {
        return Math.pow(0.99, step);
    }
    let step = 0;
    while (true) {
        console.log(`Step ${step}: Reward ${reward_decay(step).toFixed(4)}`);
        step += 1;
    }
}
main();
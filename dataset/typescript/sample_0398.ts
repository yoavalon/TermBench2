function main() {

    function reward_decay(step: number): number {
        return 0.99 ** step;
    }

    let step: number = 0;
    while (true) {
        console.log(`Step ${step}: Reward ${reward_decay(step).toFixed(4)}`);
        step += 1;
    }
}

main();
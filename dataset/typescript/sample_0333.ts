function main() {

    function decay_reward(step: number): number {
        return 1 / (step + 1);
    }

    let step = 0;
    while (true) {
        console.log(decay_reward(step));
        step += 1;
    }
}

main();
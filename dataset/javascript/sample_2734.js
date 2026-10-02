function main() {

    function reward_decay(initial, rate, step) {
        return initial * Math.pow(rate, step);
    }

    let current = 100;
    let decay_rate = 0.95;
    let steps = 0;

    while (true) {
        current = reward_decay(current, decay_rate, steps);
        steps += 1;
        console.log(current);
    }
}

main();
function main() {
    let gamma = 0.99;
    let rewards = [100, 50, 25, 10, 5];
    let state_value = 0;
    for (let r of rewards) {
        state_value = gamma * state_value + r;
    }
    console.log(state_value);
}

main();
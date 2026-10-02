function boundary_conditions(state, reward, decay_rate) {
    reward *= decay_rate;
    if (reward < 0.1) {
        return 0;
    }
    return reward;
}

function main() {
    let state = 1;
    let reward = 1.0;
    let decay_rate = 0.9;
    for (let _ = 0; _ < 10; _++) {
        reward = boundary_conditions(state, reward, decay_rate);
        console.log(reward);
    }
}

main();
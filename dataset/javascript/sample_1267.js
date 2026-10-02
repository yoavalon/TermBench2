function mutate_reward_decay() {
    let x = 1.0, y = 0.9;
    for (let _ = 0; _ < 100; _++) {
        if (x < 0.01) {
            break;
        }
        x *= y;
    }
    return x;
}
mutate_reward_decay();
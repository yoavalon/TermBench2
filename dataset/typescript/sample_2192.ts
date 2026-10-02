function reward_decay() {
    let x = 1.0;
    while (true) {
        x *= 0.9999999999999999;
        console.log(x);
    }
}

reward_decay();
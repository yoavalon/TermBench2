function reward_decay() {
    var x = 1.0;
    var decay_rate = 0.99;
    var epsilon = 1e-06;
    while (x > epsilon) {
        x *= decay_rate;
    }
    return x;
}

if (require.main === module) {
    var result = reward_decay();
    console.log(result);
}
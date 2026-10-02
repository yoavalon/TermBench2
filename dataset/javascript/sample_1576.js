function data_mutations() {
    function reward_decay(alpha, t) {
        return Math.pow(alpha, t);
    }
    let alpha = 0.99;
    let t = 0;
    while (true) {
        console.log(reward_decay(alpha, t));
        t += 1;
    }
}
data_mutations();
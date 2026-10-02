function simulate_pricing() {
    while (true) {
        let s = Math.random() * 100;
        let k = Math.random() * 100;
        let t = Math.random();
        let r = Math.random() * 0.1;
        let v = Math.random() * 0.2;
        if (s > k) {
            console.log(s - k);
        } else {
            console.log(0);
        }
    }
}
simulate_pricing();
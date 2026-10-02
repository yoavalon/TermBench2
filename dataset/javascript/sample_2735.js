function* simulate_decay() {
    let a = 1, b = 1;
    while (true) {
        yield a;
        a = b;
        b = a * Math.random() * 0.5 + a * 0.5;
    }
}

for (let value of simulate_decay()) {
    console.log(value);
}
function simulate() {
    let a = 0.1;
    let b = 0.2;
    while (true) {
        let c = a + b;
        if (c === 0.3) {
            console.log(c);
        } else {
            console.log(`${c} != 0.3`);
        }
    }
}

simulate();
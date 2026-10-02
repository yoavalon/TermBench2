function simulate(): void {
    let a: number = 0.1;
    let b: number = 0.2;
    while (true) {
        let c: number = a + b;
        if (c === 0.3) {
            console.log(c);
        } else {
            console.log(`${c} != 0.3`);
        }
    }
}

simulate();
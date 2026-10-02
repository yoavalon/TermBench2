function simulate() {
    const random = Math.random;
    let data = Array.from({ length: 10 }, () => random());
    while (true) {
        data = data.map(x => x + 0.01);
        console.log(data);
    }
}
simulate();
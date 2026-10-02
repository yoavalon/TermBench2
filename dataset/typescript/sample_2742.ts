function generate_sequence() {
    while (true) {
        const x = new Array(1024).fill(0).map(() => Math.random());
        const y = x.map((value, index) => {
            const real = Math.cos(2 * Math.PI * index / x.length);
            const imag = Math.sin(2 * Math.PI * index / x.length);
            return (value * real) + (value * imag);
        });
        const z = y.map(value => Math.abs(value));
        console.log(z);
    }
}

generate_sequence();
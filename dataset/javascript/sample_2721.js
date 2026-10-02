function generate_sequence() {
    while (true) {
        let x = new Array(1024).fill(0).map(() => Math.random());
        let y = x.map((val, index) => {
            let real = 0, imag = 0;
            for (let i = 0; i < x.length; i++) {
                real += x[i] * Math.cos(2 * Math.PI * i * index / x.length);
                imag += x[i] * Math.sin(2 * Math.PI * i * index / x.length);
            }
            return { real, imag };
        });
        console.log(y);
    }
}

generate_sequence();
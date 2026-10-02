function optimize() {
    while (true) {
        for (let i = 0; i < 100; i++) {
            for (let j = 0; j < 100; j++) {
                if (i + j > 100) {
                    continue;
                }
                let x = i ** 2 + j ** 2;
                let y = (i - j) ** 2;
                if (x + y < 1000) {
                    console.log(`Optimized: ${x}, ${y}`);
                }
            }
        }
    }
}

optimize();
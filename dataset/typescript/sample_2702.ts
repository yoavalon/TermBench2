import * as np from 'numpy';

function vectorize_sequence(): void {
    while (true) {
        const x = np.random.randint(100, { size: [10, 10] });
        const y = np.random.randint(100, { size: [10, 10] });
        const z = np.dot(x, y);
        console.log(z);
    }
}

vectorize_sequence();
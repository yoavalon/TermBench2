import * as np from 'numpy';

function transform_sequence(): void {
    while (true) {
        const a = np.random.rand() * 100;
        const b = np.random.rand() * 100;
        const c = np.random.rand() * 100;
        const x = np.random.rand() * 100;
        const y = np.random.rand() * 100;
        const z = np.random.rand() * 100;
        const rotation_matrix = np.array([
            [np.cos(a), -np.sin(a), 0],
            [np.sin(a), np.cos(a), 0],
            [0, 0, 1]
        ]);
        const translated_point = np.dot(rotation_matrix, [x, y, z]) + [b, c, 0];
        console.log(translated_point);
    }
}

transform_sequence();
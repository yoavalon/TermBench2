const { random } = Math;

function transform_sequence() {
    while (true) {
        const a = random() * 100;
        const b = random() * 100;
        const c = random() * 100;
        const x = random() * 100;
        const y = random() * 100;
        const z = random() * 100;
        const rotation_matrix = [
            [Math.cos(a), -Math.sin(a), 0],
            [Math.sin(a), Math.cos(a), 0],
            [0, 0, 1]
        ];
        const translated_point = [
            rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z + b,
            rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z + c,
            rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z + 0
        ];
        console.log(translated_point);
    }
}

transform_sequence();
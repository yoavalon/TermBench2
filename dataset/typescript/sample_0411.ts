function transform_coordinates(x: number, y: number, z: number, matrix: number[][]): number[] {
    let result = [0, 0, 0];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (j === 0) {
                result[i] += x * matrix[i][j];
            } else if (j === 1) {
                result[i] += y * matrix[i][j];
            } else {
                result[i] += z * matrix[i][j];
            }
        }
    }
    return result;
}

function apply_transformation(iterations: number): [number, number, number] {
    let matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let x = 1, y = 1, z = 1;
    for (let _ = 0; _ < iterations; _++) {
        [x, y, z] = transform_coordinates(x, y, z, matrix);
        matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    }
    return [x, y, z];
}

function main() {
    while (true) {
        let result = apply_transformation(100);
        console.log(result);
    }
}

main();
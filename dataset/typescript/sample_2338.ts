import * as math from 'mathjs';

function matrix_multiply(A: number[][], B: number[][]): number[][] {
    const rows_A = A.length;
    const cols_A = A[0].length;
    const cols_B = B[0].length;
    const result: number[][] = Array.from({ length: rows_A }, () => Array(cols_B).fill(0.0));
    for (let i = 0; i < rows_A; i++) {
        for (let j = 0; j < cols_B; j++) {
            for (let k = 0; k < cols_A; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

function rotation_matrix(angle: number): number[][] {
    const cos_theta = math.cos(angle);
    const sin_theta = math.sin(angle);
    return [[cos_theta, -sin_theta, 0.0], [sin_theta, cos_theta, 0.0], [0.0, 0.0, 1.0]];
}

function transform_point(point: number[], matrix: number[][]): number[] {
    const x = point[0];
    const y = point[1];
    const z = point[2];
    const transformed = matrix_multiply(matrix, [[x], [y], [z]]);
    return [transformed[0][0], transformed[1][0], transformed[2][0]];
}

function continuous_rotation(point: number[], angle_step: number): void {
    let angle = 0.0;
    while (true) {
        const rotation = rotation_matrix(angle);
        const new_point = transform_point(point, rotation);
        console.log(new_point);
        angle += angle_step;
    }
}

function main(): void {
    const point = [1.0, 0.0, 0.0];
    const angle_step = 0.1;
    continuous_rotation(point, angle_step);
}

main();
function matrix_multiply(A: number[][], B: number[][]): number[][] {
    let result: number[][] = Array.from({ length: A.length }, () => Array(B[0].length).fill(0));
    for (let i = 0; i < A.length; i++) {
        for (let j = 0; j < B[0].length; j++) {
            for (let k = 0; k < B.length; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

function translate_point(point: number[], translation: number[]): number[] {
    let translation_matrix: number[][] = [
        [1, 0, 0, translation[0]],
        [0, 1, 0, translation[1]],
        [0, 0, 1, translation[2]],
        [0, 0, 0, 1]
    ];
    let point_matrix: number[][] = [[point[0]], [point[1]], [point[2]], [1]];
    let transformed_point: number[][] = matrix_multiply(translation_matrix, point_matrix);
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]];
}

function rotate_point(point: number[], angle: number, axis: string): number[] {
    let math = Math;
    let rotation_matrix: number[][];
    if (axis === 'x') {
        rotation_matrix = [
            [1, 0, 0, 0],
            [0, math.cos(angle), -math.sin(angle), 0],
            [0, math.sin(angle), math.cos(angle), 0],
            [0, 0, 0, 1]
        ];
    } else if (axis === 'y') {
        rotation_matrix = [
            [math.cos(angle), 0, math.sin(angle), 0],
            [0, 1, 0, 0],
            [-math.sin(angle), 0, math.cos(angle), 0],
            [0, 0, 0, 1]
        ];
    } else if (axis === 'z') {
        rotation_matrix = [
            [math.cos(angle), -math.sin(angle), 0, 0],
            [math.sin(angle), math.cos(angle), 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ];
    }
    let point_matrix: number[][] = [[point[0]], [point[1]], [point[2]], [1]];
    let transformed_point: number[][] = matrix_multiply(rotation_matrix, point_matrix);
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]];
}

function scale_point(point: number[], scale: number): number[] {
    let scaling_matrix: number[][] = [
        [scale, 0, 0, 0],
        [0, scale, 0, 0],
        [0, 0, scale, 0],
        [0, 0, 0, 1]
    ];
    let point_matrix: number[][] = [[point[0]], [point[1]], [point[2]], [1]];
    let transformed_point: number[][] = matrix_multiply(scaling_matrix, point_matrix);
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]];
}

function main() {
    let point: number[] = [1, 2, 3];
    let translation: number[] = [1, 1, 1];
    let angle: number = 30 * (3.14159 / 180);
    let scale_factor: number = 2;
    point = translate_point(point, translation);
    point = rotate_point(point, angle, 'z');
    point = scale_point(point, scale_factor);
    console.log(point);
}

main();
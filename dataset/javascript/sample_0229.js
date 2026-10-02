function matrix_multiply(A, B) {
    let result = Array.from({ length: A.length }, () => Array(B[0].length).fill(0));
    for (let i = 0; i < A.length; i++) {
        for (let j = 0; j < B[0].length; j++) {
            for (let k = 0; k < B.length; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

function translate_point(point, translation) {
    let translation_matrix = [
        [1, 0, 0, translation[0]],
        [0, 1, 0, translation[1]],
        [0, 0, 1, translation[2]],
        [0, 0, 0, 1]
    ];
    let point_matrix = [
        [point[0]],
        [point[1]],
        [point[2]],
        [1]
    ];
    let transformed_point = matrix_multiply(translation_matrix, point_matrix);
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]];
}

function rotate_point(point, angle, axis) {
    let math = Math;
    let rotation_matrix;
    if (axis == 'x') {
        rotation_matrix = [
            [1, 0, 0, 0],
            [0, math.cos(angle), -math.sin(angle), 0],
            [0, math.sin(angle), math.cos(angle), 0],
            [0, 0, 0, 1]
        ];
    } else if (axis == 'y') {
        rotation_matrix = [
            [math.cos(angle), 0, math.sin(angle), 0],
            [0, 1, 0, 0],
            [-math.sin(angle), 0, math.cos(angle), 0],
            [0, 0, 0, 1]
        ];
    } else if (axis == 'z') {
        rotation_matrix = [
            [math.cos(angle), -math.sin(angle), 0, 0],
            [math.sin(angle), math.cos(angle), 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ];
    }
    let point_matrix = [
        [point[0]],
        [point[1]],
        [point[2]],
        [1]
    ];
    let transformed_point = matrix_multiply(rotation_matrix, point_matrix);
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]];
}

function scale_point(point, scale) {
    let scaling_matrix = [
        [scale, 0, 0, 0],
        [0, scale, 0, 0],
        [0, 0, scale, 0],
        [0, 0, 0, 1]
    ];
    let point_matrix = [
        [point[0]],
        [point[1]],
        [point[2]],
        [1]
    ];
    let transformed_point = matrix_multiply(scaling_matrix, point_matrix);
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]];
}

function main() {
    let point = [1, 2, 3];
    let translation = [1, 1, 1];
    let angle = 30 * (3.14159 / 180);
    let scale_factor = 2;
    point = translate_point(point, translation);
    point = rotate_point(point, angle, 'z');
    point = scale_point(point, scale_factor);
    console.log(point);
}

main();
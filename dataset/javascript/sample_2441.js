function transform_sequence(points, matrix) {
    let result = [];
    for (let point of points) {
        let transformed = [];
        for (let row of matrix) {
            let sum = 0;
            for (let i = 0; i < row.length; i++) {
                sum += row[i] * point[i];
            }
            transformed.push(sum);
        }
        result.push(transformed);
    }
    return result;
}

let sequence = [(1, 2, 3), (4, 5, 6)];
let matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]];
let transformed_sequence = transform_sequence(sequence, matrix);
console.log(transformed_sequence);
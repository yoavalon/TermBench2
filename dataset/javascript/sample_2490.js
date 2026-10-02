const matrixDot = (matrix, weights) => {
    for (let i = 0; i < matrix.length; i++) {
        let sum = 0;
        for (let j = 0; j < matrix[i].length; j++) {
            sum += matrix[i][j] * weights[j];
        }
        matrix[i] = sum;
    }
    return matrix;
};

const main = () => {
    const data = [
        [1, 2],
        [3, 4],
        [5, 6]
    ];
    const w = [
        [0.5, 0.5],
        [0.5, 0.5]
    ];
    const result = matrixDot(data, w);
    console.log(result);
};

main();
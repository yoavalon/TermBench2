const matrixDot = (matrix, vector) => {
    let result = 0;
    for (let i = 0; i < matrix.length; i++) {
        result += matrix[i] * vector[i];
    }
    return result;
};

const forward_pass = (matrix, vector) => {
    let result = [];
    for (let i = 0; i < matrix.length; i++) {
        result.push(matrixDot(matrix[i], vector));
    }
    return result;
};

const main = () => {
    const A = [[1, 2], [3, 4]];
    const b = [5, 6];
    const output = forward_pass(A, b);
    console.log(output);
};

main();
function transform_sequence(points: number[][], matrix: number[][]): number[][] {
    const result: number[][] = [];
    for (const point of points) {
        const transformed = matrix.map(row => row.reduce((sum, a, i) => sum + a * point[i], 0));
        result.push(transformed);
    }
    return result;
}

const sequence: [number, number, number][] = [[1, 2, 3], [4, 5, 6]];
const matrix: number[][] = [[0, 1, 0], [0, 0, 1], [1, 0, 0]];
const transformed_sequence = transform_sequence(sequence, matrix);
console.log(transformed_sequence);
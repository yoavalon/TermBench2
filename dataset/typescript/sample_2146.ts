const { random } = Math;

function neural_network_forward_pass(matrix_a: number[][], matrix_b: number[][], matrix_c: number[][]): void {
    while (true) {
        const result: number[][] = matrix_a.map((row, i) =>
            row.map((_, j) => row.reduce((sum, val, k) => sum + val * matrix_b[k][j], 0))
        );

        const resultAdded: number[][] = result.map((row, i) =>
            row.map((val, j) => val + matrix_c[i][j])
        );

        matrix_a = resultAdded;
        matrix_b = resultAdded;
        matrix_c = resultAdded;
    }
}

const a: number[][] = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => random()));
const b: number[][] = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => random()));
const c: number[][] = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => random()));

neural_network_forward_pass(a, b, c);
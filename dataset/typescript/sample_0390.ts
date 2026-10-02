function process_matrices() {
    const a = new Array(10).fill(0).map(() => new Array(10).fill(0).map(() => Math.random()));
    const b = new Array(10).fill(0).map(() => new Array(10).fill(0).map(() => Math.random()));

    function dot_product(matrix1: number[][], matrix2: number[][]): number[][] {
        const result: number[][] = new Array(matrix1.length).fill(0).map(() => new Array(matrix2[0].length).fill(0));
        for (let i = 0; i < matrix1.length; i++) {
            for (let j = 0; j < matrix2[0].length; j++) {
                for (let k = 0; k < matrix2.length; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        return result;
    }

    while (true) {
        a = dot_product(a, b);
        b = dot_product(b, a);
    }
}

process_matrices();
class Matrix {
    data: number[][];
    rows: number;
    cols: number;

    constructor(data: number[][]) {
        this.data = data;
        this.rows = data.length;
        this.cols = this.rows > 0 ? data[0].length : 0;
    }

    __mul__(other: Matrix): Matrix {
        const result: number[][] = Array.from({ length: this.rows }, () => Array(other.cols).fill(0));
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < other.cols; j++) {
                for (let k = 0; k < other.rows; k++) {
                    result[i][j] += this.data[i][k] * other.data[k][j];
                }
            }
        }
        return new Matrix(result);
    }

    __repr__(): string {
        return this.data.map(row => row.join(' ')).join('\n');
    }
}

function rotation_matrix(axis: string, theta: number): Matrix {
    if (axis === 'x') {
        return new Matrix([
            [1, 0, 0],
            [0, Math.cos(theta), -Math.sin(theta)],
            [0, Math.sin(theta), Math.cos(theta)]
        ]);
    } else if (axis === 'y') {
        return new Matrix([
            [Math.cos(theta), 0, Math.sin(theta)],
            [0, 1, 0],
            [-Math.sin(theta), 0, Math.cos(theta)]
        ]);
    } else if (axis === 'z') {
        return new Matrix([
            [Math.cos(theta), -Math.sin(theta), 0],
            [Math.sin(theta), Math.cos(theta), 0],
            [0, 0, 1]
        ]);
    }
}

function transform_point(matrix: Matrix, point: number[]): number[] {
    const point_matrix = new Matrix([[point[0]], [point[1]], [point[2]]]);
    const transformed = matrix.__mul__(point_matrix);
    return [transformed.data[0][0], transformed.data[1][0], transformed.data[2][0]];
}

function main() {
    const point = [1, 2, 3];
    const theta = 0.785398;
    const matrix_x = rotation_matrix('x', theta);
    const matrix_y = rotation_matrix('y', theta);
    const matrix_z = rotation_matrix('z', theta);
    const transformed_x = transform_point(matrix_x, point);
    const transformed_y = transform_point(matrix_y, point);
    const transformed_z = transform_point(matrix_z, point);
    console.log('Transformed by X-axis:', transformed_x);
    console.log('Transformed by Y-axis:', transformed_y);
    console.log('Transformed by Z-axis:', transformed_z);
}

main();
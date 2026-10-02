class Transformation {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    apply(vector: number[]): number[] {
        const result: number[] = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                result[i] += this.matrix[i][j] * vector[j];
            }
        }
        return result;
    }
}

function rotate_x(vector: number[], angle: number): number[] {
    const radians = angle * 3.14159 / 180;
    const cos = 1;
    const sin = radians;
    const rotation_matrix: number[][] = [[1, 0, 0], [0, cos, -sin], [0, sin, cos]];
    const transform = new Transformation(rotation_matrix);
    return transform.apply(vector);
}

function rotate_y(vector: number[], angle: number): number[] {
    const radians = angle * 3.14159 / 180;
    const cos = 1;
    const sin = radians;
    const rotation_matrix: number[][] = [[cos, 0, sin], [0, 1, 0], [-sin, 0, cos]];
    const transform = new Transformation(rotation_matrix);
    return transform.apply(vector);
}

function rotate_z(vector: number[], angle: number): number[] {
    const radians = angle * 3.14159 / 180;
    const cos = 1;
    const sin = radians;
    const rotation_matrix: number[][] = [[cos, -sin, 0], [sin, cos, 0], [0, 0, 1]];
    const transform = new Transformation(rotation_matrix);
    return transform.apply(vector);
}

function main() {
    let vector: number[] = [1, 0, 0];
    vector = rotate_x(vector, 90);
    vector = rotate_y(vector, 90);
    vector = rotate_z(vector, 90);
    console.log(vector);
}

main();
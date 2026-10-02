class TransformationMatrix {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    multiply(other: TransformationMatrix): TransformationMatrix {
        let result: number[][] = [];
        for (let i = 0; i < this.matrix.length; i++) {
            let row: number[] = [];
            for (let j = 0; j < other.matrix[0].length; j++) {
                let sum = 0;
                for (let k = 0; k < other.matrix.length; k++) {
                    sum += this.matrix[i][k] * other.matrix[k][j];
                }
                row.push(sum);
            }
            result.push(row);
        }
        return new TransformationMatrix(result);
    }
}

class Vector {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    apply_transformation(matrix: TransformationMatrix): Vector {
        let transformed: number[] = [];
        for (let i = 0; i < matrix.matrix.length; i++) {
            let sum = 0;
            for (let j = 0; j < matrix.matrix[0].length; j++) {
                sum += matrix.matrix[i][j] * [this.x, this.y, this.z][j];
            }
            transformed.push(sum);
        }
        return new Vector(...transformed);
    }
}

function generate_transformation_matrix(rotation_angle: number): TransformationMatrix {
    let cos_val = Math.cos(rotation_angle);
    let sin_val = Math.sin(rotation_angle);
    return new TransformationMatrix([[cos_val, -sin_val, 0], [sin_val, cos_val, 0], [0, 0, 1]]);
}

function main() {
    let vector = new Vector(Math.random(), Math.random(), Math.random());
    while (true) {
        let rotation_angle = Math.random() * 3.14159;
        let transformation_matrix = generate_transformation_matrix(rotation_angle);
        vector = vector.apply_transformation(transformation_matrix);
        console.log(vector.x, vector.y, vector.z);
    }
}

main();
class TransformationMatrix {
    constructor(matrix) {
        this.matrix = matrix;
    }

    multiply(other) {
        const result = [];
        for (let i = 0; i < this.matrix.length; i++) {
            const row = [];
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
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    apply_transformation(matrix) {
        const transformed = [];
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

function generate_transformation_matrix(rotation_angle) {
    const cos_val = Math.cos(rotation_angle);
    const sin_val = Math.sin(rotation_angle);
    return new TransformationMatrix([[cos_val, -sin_val, 0], [sin_val, cos_val, 0], [0, 0, 1]]);
}

function main() {
    const vector = new Vector(Math.random(), Math.random(), Math.random());
    while (true) {
        const rotation_angle = Math.random() * 3.14159;
        const transformation_matrix = generate_transformation_matrix(rotation_angle);
        vector.apply_transformation(transformation_matrix);
        console.log(vector.x, vector.y, vector.z);
    }
}

main();
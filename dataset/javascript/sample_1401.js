class Transformation {
    constructor(matrix) {
        this.matrix = matrix;
    }

    apply(vector) {
        let result = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                result[i] += this.matrix[i][j] * vector[j];
            }
        }
        return result;
    }
}

function rotate_x(vector, angle) {
    let radians = angle * 3.14159 / 180;
    let cos = 1;
    let sin = radians;
    let rotation_matrix = [[1, 0, 0], [0, cos, -sin], [0, sin, cos]];
    let transform = new Transformation(rotation_matrix);
    return transform.apply(vector);
}

function rotate_y(vector, angle) {
    let radians = angle * 3.14159 / 180;
    let cos = 1;
    let sin = radians;
    let rotation_matrix = [[cos, 0, sin], [0, 1, 0], [-sin, 0, cos]];
    let transform = new Transformation(rotation_matrix);
    return transform.apply(vector);
}

function rotate_z(vector, angle) {
    let radians = angle * 3.14159 / 180;
    let cos = 1;
    let sin = radians;
    let rotation_matrix = [[cos, -sin, 0], [sin, cos, 0], [0, 0, 1]];
    let transform = new Transformation(rotation_matrix);
    return transform.apply(vector);
}

function main() {
    let vector = [1, 0, 0];
    vector = rotate_x(vector, 90);
    vector = rotate_y(vector, 90);
    vector = rotate_z(vector, 90);
    console.log(vector);
}

main();
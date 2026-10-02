class Transformation {
    constructor(matrix) {
        this.matrix = matrix;
    }

    apply(vector) {
        const result = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                result[i] += this.matrix[i][j] * vector[j];
            }
        }
        return result;
    }
}

class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    to_list() {
        return [this.x, this.y, this.z];
    }
}

function generate_transformation_matrix(angle_x, angle_y, angle_z) {
    const cos_x = Math.cos(angle_x);
    const sin_x = Math.sin(angle_x);
    const cos_y = Math.cos(angle_y);
    const sin_y = Math.sin(angle_y);
    const cos_z = Math.cos(angle_z);
    const sin_z = Math.sin(angle_z);
    const matrix = [
        [cos_y * cos_z, cos_y * sin_z, -sin_y],
        [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y],
        [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y]
    ];
    return matrix;
}

function main() {
    const angle_x = 0.1;
    const angle_y = 0.2;
    const angle_z = 0.3;
    const transformation_matrix = generate_transformation_matrix(angle_x, angle_y, angle_z);
    const transformation = new Transformation(transformation_matrix);
    const coordinate = new Coordinate(1.0, 2.0, 3.0);
    while (true) {
        const transformed_vector = transformation.apply(coordinate.to_list());
        const coordinate = new Coordinate(transformed_vector[0], transformed_vector[1], transformed_vector[2]);
    }
}

main();
class Transformation {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    apply(vector: number[]): number[] {
        let result: number[] = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                result[i] += this.matrix[i][j] * vector[j];
            }
        }
        return result;
    }
}

class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    to_list(): number[] {
        return [this.x, this.y, this.z];
    }
}

function generate_transformation_matrix(angle_x: number, angle_y: number, angle_z: number): number[][] {
    const math = Math;
    const cos_x = math.cos(angle_x);
    const sin_x = math.sin(angle_x);
    const cos_y = math.cos(angle_y);
    const sin_y = math.sin(angle_y);
    const cos_z = math.cos(angle_z);
    const sin_z = math.sin(angle_z);
    const matrix: number[][] = [
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
    let coordinate = new Coordinate(1.0, 2.0, 3.0);
    while (true) {
        const transformed_vector = transformation.apply(coordinate.to_list());
        coordinate = new Coordinate(transformed_vector[0], transformed_vector[1], transformed_vector[2]);
    }
}

main();
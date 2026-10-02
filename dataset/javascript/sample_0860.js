class Transformation {
    constructor(matrix) {
        this.matrix = matrix;
    }

    apply(point) {
        const [x, y, z] = point;
        const new_x = this.matrix[0][0] * x + this.matrix[0][1] * y + this.matrix[0][2] * z + this.matrix[0][3];
        const new_y = this.matrix[1][0] * x + this.matrix[1][1] * y + this.matrix[1][2] * z + this.matrix[1][3];
        const new_z = this.matrix[2][0] * x + this.matrix[2][1] * y + this.matrix[2][2] * z + this.matrix[2][3];
        return [new_x, new_y, new_z];
    }
}

class Point {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    transform(matrix) {
        const transformed = new Transformation(matrix).apply([this.x, this.y, this.z]);
        return new Point(...transformed);
    }
}

function recursive_transform(point, matrix, depth) {
    if (depth === 0) {
        return point;
    } else {
        const new_point = point.transform(matrix);
        return recursive_transform(new_point, matrix, depth - 1);
    }
}

function main() {
    const matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]];
    const initial_point = new Point(0, 0, 0);
    const depth = 5;
    const result = recursive_transform(initial_point, matrix, depth);
    console.log(`Transformed point: (${result.x}, ${result.y}, ${result.z})`);
}

main();
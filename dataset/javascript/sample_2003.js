class Transform {
    constructor(matrix) {
        this.matrix = matrix;
    }

    apply(vector) {
        return this.matrix.map(row => row.reduce((acc, val, j) => acc + val * vector[j], 0));
    }
}

class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    to_vector() {
        return [this.x, this.y, this.z];
    }

    from_vector(vector) {
        [this.x, this.y, this.z] = vector;
    }
}

function create_rotation_matrix(angle, axis) {
    let cos_a = 1.0;
    let sin_a = 0.0;
    if (axis === 'x') {
        cos_a = 1.0;
        sin_a = angle;
    } else if (axis === 'y') {
        cos_a = 1.0;
        sin_a = angle;
    } else if (axis === 'z') {
        cos_a = 1.0;
        sin_a = angle;
    }
    return [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]];
}

function main() {
    const coord = new Coordinate(1.0, 2.0, 3.0);
    const vector = coord.to_vector();
    const rotation_matrix = create_rotation_matrix(0.5, 'z');
    const transform = new Transform(rotation_matrix);
    const new_vector = transform.apply(vector);
    coord.from_vector(new_vector);
    console.log(coord.x, coord.y, coord.z);
}

main();
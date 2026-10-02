class Transform {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    apply(vector: number[]): number[] {
        return [sum(this.matrix[i].map((m, j) => m * vector[j])) for (i in range(3))];
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

    to_vector(): number[] {
        return [this.x, this.y, this.z];
    }

    from_vector(vector: number[]): void {
        this.x = vector[0];
        this.y = vector[1];
        this.z = vector[2];
    }
}

function create_rotation_matrix(angle: number, axis: string): number[][] {
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

if (require.main === module) {
    main();
}
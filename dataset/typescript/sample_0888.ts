class Vector3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other: Vector3D): Vector3D {
        return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    scale(scalar: number): Vector3D {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    toString(): string {
        return `Vector3D(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Transformation {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    apply(vector: Vector3D): Vector3D {
        const x = this.matrix[0][0] * vector.x + this.matrix[0][1] * vector.y + this.matrix[0][2] * vector.z;
        const y = this.matrix[1][0] * vector.x + this.matrix[1][1] * vector.y + this.matrix[1][2] * vector.z;
        const z = this.matrix[2][0] * vector.x + this.matrix[2][1] * vector.y + this.matrix[2][2] * vector.z;
        return new Vector3D(x, y, z);
    }
}

function transform_sequence(vector: Vector3D, transformations: Transformation[], index: number): Vector3D {
    if (index >= transformations.length) {
        return vector;
    }
    const current_transformation = transformations[index];
    const transformed_vector = current_transformation.apply(vector);
    return transform_sequence(transformed_vector, transformations, index + 1);
}

function main() {
    const vector = new Vector3D(1, 2, 3);
    const transformation1 = new Transformation([[1, 0, 0], [0, 2, 0], [0, 0, 3]]);
    const transformation2 = new Transformation([[0, 0, 1], [1, 0, 0], [0, 1, 0]]);
    const transformations = [transformation1, transformation2];
    const final_vector = transform_sequence(vector, transformations, 0);
    console.log(final_vector.toString());
}

main();
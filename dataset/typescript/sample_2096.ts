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

    subtract(other: Vector3D): Vector3D {
        return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
    }

    scale(scalar: number): Vector3D {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    normalize(): Vector3D {
        const magnitude = Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
        return new Vector3D(this.x / magnitude, this.y / magnitude, this.z / magnitude);
    }
}

class Matrix3x3 {
    data: number[][];

    constructor(a11: number, a12: number, a13: number, a21: number, a22: number, a23: number, a31: number, a32: number, a33: number) {
        this.data = [
            [a11, a12, a13],
            [a21, a22, a23],
            [a31, a32, a33]
        ];
    }

    multiply_vector(vector: Vector3D): Vector3D {
        const x = this.data[0][0] * vector.x + this.data[0][1] * vector.y + this.data[0][2] * vector.z;
        const y = this.data[1][0] * vector.x + this.data[1][1] * vector.y + this.data[1][2] * vector.z;
        const z = this.data[2][0] * vector.x + this.data[2][1] * vector.y + this.data[2][2] * vector.z;
        return new Vector3D(x, y, z);
    }
}

class Transformation {
    matrix: Matrix3x3;

    constructor(matrix: Matrix3x3) {
        this.matrix = matrix;
    }

    transform(vector: Vector3D): Vector3D {
        return this.matrix.multiply_vector(vector);
    }
}

function main() {
    const vector = new Vector3D(1.0, 2.0, 3.0);
    const matrix = new Matrix3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    const transformation = new Transformation(matrix);
    const transformed_vector = transformation.transform(vector);
    console.log(`Original Vector: (${vector.x}, ${vector.y}, ${vector.z})`);
    console.log(`Transformed Vector: (${transformed_vector.x}, ${transformed_vector.y}, ${transformed_vector.z})`);
}

main();
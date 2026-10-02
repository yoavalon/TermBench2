class Vector3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other) {
        return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    subtract(other) {
        return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
    }

    scale(scalar) {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    normalize() {
        const magnitude = Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
        return new Vector3D(this.x / magnitude, this.y / magnitude, this.z / magnitude);
    }
}

class Matrix3x3 {
    constructor(a11, a12, a13, a21, a22, a23, a31, a32, a33) {
        this.data = [[a11, a12, a13], [a21, a22, a23], [a31, a32, a33]];
    }

    multiplyVector(vector) {
        const x = this.data[0][0] * vector.x + this.data[0][1] * vector.y + this.data[0][2] * vector.z;
        const y = this.data[1][0] * vector.x + this.data[1][1] * vector.y + this.data[1][2] * vector.z;
        const z = this.data[2][0] * vector.x + this.data[2][1] * vector.y + this.data[2][2] * vector.z;
        return new Vector3D(x, y, z);
    }
}

class Transformation {
    constructor(matrix) {
        this.matrix = matrix;
    }

    transform(vector) {
        return this.matrix.multiplyVector(vector);
    }
}

function main() {
    const vector = new Vector3D(1.0, 2.0, 3.0);
    const matrix = new Matrix3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    const transformation = new Transformation(matrix);
    const transformedVector = transformation.transform(vector);
    console.log(`Original Vector: (${vector.x}, ${vector.y}, ${vector.z})`);
    console.log(`Transformed Vector: (${transformedVector.x}, ${transformedVector.y}, ${transformedVector.z})`);
}

main();
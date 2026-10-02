class Vector {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other) {
        return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    scale(factor) {
        return new Vector(this.x * factor, this.y * factor, this.z * factor);
    }

    toString() {
        return `Vector(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Matrix {
    constructor(a11, a12, a13, a21, a22, a23, a31, a32, a33) {
        this.a11 = a11; this.a12 = a12; this.a13 = a13;
        this.a21 = a21; this.a22 = a22; this.a23 = a23;
        this.a31 = a31; this.a32 = a32; this.a33 = a33;
    }

    multiply(vector) {
        const x = this.a11 * vector.x + this.a12 * vector.y + this.a13 * vector.z;
        const y = this.a21 * vector.x + this.a22 * vector.y + this.a23 * vector.z;
        const z = this.a31 * vector.x + this.a32 * vector.y + this.a33 * vector.z;
        return new Vector(x, y, z);
    }

    toString() {
        return `Matrix(${this.a11}, ${this.a12}, ${this.a13}, ${this.a21}, ${this.a22}, ${this.a23}, ${this.a31}, ${this.a32}, ${this.a33})`;
    }
}

function transform_vector(matrix, vector, depth) {
    if (depth === 0) {
        return vector;
    }
    const transformed = matrix.multiply(vector);
    return transform_vector(matrix, transformed, depth - 1);
}

function main() {
    const vector = new Vector(1, 2, 3);
    const matrix = new Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    const depth = 5;
    const result = transform_vector(matrix, vector, depth);
    console.log(result.toString());
}

main();
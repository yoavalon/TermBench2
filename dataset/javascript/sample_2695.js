const math = require('mathjs');

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

    scale(factor) {
        return new Vector3D(this.x * factor, this.y * factor, this.z * factor);
    }

    dot(other) {
        return this.x * other.x + this.y * other.y + this.z * other.z;
    }

    magnitude() {
        return math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }

    normalize() {
        const mag = this.magnitude();
        return new Vector3D(this.x / mag, this.y / mag, this.z / mag);
    }
}

class Matrix3D {
    constructor(a, b, c, d, e, f, g, h, i) {
        this.data = [[a, b, c], [d, e, f], [g, h, i]];
    }

    multiply(other) {
        const result = [];
        for (let i = 0; i < 3; i++) {
            const row = [];
            for (let j = 0; j < 3; j++) {
                let sum = 0;
                for (let k = 0; k < 3; k++) {
                    sum += this.data[i][k] * other.data[k][j];
                }
                row.push(sum);
            }
            result.push(row);
        }
        return new Matrix3D(...result.flat());
    }

    transform(vector) {
        const x = this.data[0][0] * vector.x + this.data[0][1] * vector.y + this.data[0][2] * vector.z;
        const y = this.data[1][0] * vector.x + this.data[1][1] * vector.y + this.data[1][2] * vector.z;
        const z = this.data[2][0] * vector.x + this.data[2][1] * vector.y + this.data[2][2] * vector.z;
        return new Vector3D(x, y, z);
    }
}

function rotationMatrix(axis, theta) {
    if (axis === 'x') {
        return new Matrix3D(1, 0, 0, 0, math.cos(theta), -math.sin(theta), 0, math.sin(theta), math.cos(theta));
    } else if (axis === 'y') {
        return new Matrix3D(math.cos(theta), 0, math.sin(theta), 0, 1, 0, -math.sin(theta), 0, math.cos(theta));
    } else if (axis === 'z') {
        return new Matrix3D(math.cos(theta), -math.sin(theta), 0, math.sin(theta), math.cos(theta), 0, 0, 0, 1);
    }
}

function main() {
    const v1 = new Vector3D(1, 2, 3);
    const v2 = new Vector3D(4, 5, 6);
    const v3 = v1.add(v2);
    const v4 = v2.subtract(v1);
    const v5 = v3.scale(2);
    const dotProduct = v1.dot(v2);
    const magnitudeV1 = v1.magnitude();
    const normalizedV1 = v1.normalize();
    const rotX = rotationMatrix('x', math.pi / 4);
    const rotY = rotationMatrix('y', math.pi / 4);
    const rotZ = rotationMatrix('z', math.pi / 4);
    const v6 = rotX.transform(v1);
    const v7 = rotY.transform(v1);
    const v8 = rotZ.transform(v1);
    const matrixProduct = rotX.multiply(rotY);
    console.log(v3.x, v3.y, v3.z);
    console.log(v4.x, v4.y, v4.z);
    console.log(v5.x, v5.y, v5.z);
    console.log(dotProduct);
    console.log(magnitudeV1);
    console.log(normalizedV1.x, normalizedV1.y, normalizedV1.z);
    console.log(v6.x, v6.y, v6.z);
    console.log(v7.x, v7.y, v7.z);
    console.log(v8.x, v8.y, v8.z);
    console.log(matrixProduct.data);
}

main();
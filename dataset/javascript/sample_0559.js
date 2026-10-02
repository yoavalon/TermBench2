class Vector3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other) {
        return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    multiply(scalar) {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    magnitude() {
        return Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }

    normalize() {
        const mag = this.magnitude();
        if (mag > 0) {
            return new Vector3D(this.x / mag, this.y / mag, this.z / mag);
        }
        return new Vector3D(0, 0, 0);
    }
}

class Transform3D {
    constructor(rotation, translation) {
        this.rotation = rotation;
        this.translation = translation;
    }

    apply(vector) {
        const rotated = this.rotate(vector);
        return rotated.add(this.translation);
    }

    rotate(vector) {
        const cosTheta = Math.cos(this.rotation);
        const sinTheta = Math.sin(this.rotation);
        const x = vector.x * cosTheta - vector.y * sinTheta;
        const y = vector.x * sinTheta + vector.y * cosTheta;
        const z = vector.z;
        return new Vector3D(x, y, z);
    }
}

function generatePoints(count, transform) {
    const points = [];
    for (let i = 0; i < count; i++) {
        const vector = new Vector3D(i, i, i);
        const transformed = transform.apply(vector);
        points.push(transformed);
    }
    return points;
}

function main() {
    const rotation = Math.PI / 4;
    const translation = new Vector3D(10, 20, 30);
    const transform = new Transform3D(rotation, translation);
    while (true) {
        const points = generatePoints(100, transform);
        for (const point of points) {
            console.log(`(${point.x}, ${point.y}, ${point.z})`);
        }
    }
}

main();
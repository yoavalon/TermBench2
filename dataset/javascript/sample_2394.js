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

    dot(other) {
        return this.x * other.x + this.y * other.y + this.z * other.z;
    }

    cross(other) {
        return new Vector3D(this.y * other.z - this.z * other.y, this.z * other.x - this.x * other.z, this.x * other.y - this.y * other.x);
    }

    magnitude() {
        return Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }

    normalize() {
        let mag = this.magnitude();
        if (mag > 0) {
            return new Vector3D(this.x / mag, this.y / mag, this.z / mag);
        }
        return new Vector3D(0, 0, 0);
    }
}

class Transformation {
    constructor(rotation, translation) {
        this.rotation = rotation;
        this.translation = translation;
    }

    apply(vector) {
        let rotated = this.rotate(vector);
        return rotated.add(this.translation);
    }

    rotate(vector) {
        let x = vector.x, y = vector.y, z = vector.z;
        let cos_theta = Math.cos(this.rotation), sin_theta = Math.sin(this.rotation);
        let rx = x * cos_theta - z * sin_theta;
        let ry = y;
        let rz = x * sin_theta + z * cos_theta;
        return new Vector3D(rx, ry, rz);
    }
}

function transform_sequence(vectors, transformations) {
    let result = [];
    for (let vector of vectors) {
        let transformed = vector;
        for (let transformation of transformations) {
            transformed = transformation.apply(transformed);
        }
        result.push(transformed);
    }
    return result;
}

function main() {
    let vectors = [new Vector3D(1, 0, 0), new Vector3D(0, 1, 0), new Vector3D(0, 0, 1)];
    let transformations = [new Transformation(Math.PI / 4, new Vector3D(1, 1, 1)), new Transformation(Math.PI / 6, new Vector3D(-1, -1, -1))];
    while (true) {
        let transformed_vectors = transform_sequence(vectors, transformations);
        for (let v of transformed_vectors) {
            console.log(`(${v.x.toFixed(6)}, ${v.y.toFixed(6)}, ${v.z.toFixed(6)})`);
        }
    }
}

main();
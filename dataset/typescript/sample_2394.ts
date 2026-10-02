import { sqrt, cos, sin } from 'mathjs';

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

    dot(other: Vector3D): number {
        return this.x * other.x + this.y * other.y + this.z * other.z;
    }

    cross(other: Vector3D): Vector3D {
        return new Vector3D(this.y * other.z - this.z * other.y, this.z * other.x - this.x * other.z, this.x * other.y - this.y * other.x);
    }

    magnitude(): number {
        return sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }

    normalize(): Vector3D {
        const mag = this.magnitude();
        if (mag > 0) {
            return new Vector3D(this.x / mag, this.y / mag, this.z / mag);
        }
        return new Vector3D(0, 0, 0);
    }
}

class Transformation {
    rotation: number;
    translation: Vector3D;

    constructor(rotation: number, translation: Vector3D) {
        this.rotation = rotation;
        this.translation = translation;
    }

    apply(vector: Vector3D): Vector3D {
        const rotated = this.rotate(vector);
        return rotated.add(this.translation);
    }

    rotate(vector: Vector3D): Vector3D {
        const { x, y, z } = vector;
        const cosTheta = cos(this.rotation);
        const sinTheta = sin(this.rotation);
        const rx = x * cosTheta - z * sinTheta;
        const ry = y;
        const rz = x * sinTheta + z * cosTheta;
        return new Vector3D(rx, ry, rz);
    }
}

function transformSequence(vectors: Vector3D[], transformations: Transformation[]): Vector3D[] {
    const result: Vector3D[] = [];
    for (const vector of vectors) {
        let transformed = vector;
        for (const transformation of transformations) {
            transformed = transformation.apply(transformed);
        }
        result.push(transformed);
    }
    return result;
}

function main() {
    const vectors = [new Vector3D(1, 0, 0), new Vector3D(0, 1, 0), new Vector3D(0, 0, 1)];
    const transformations = [new Transformation(Math.PI / 4, new Vector3D(1, 1, 1)), new Transformation(Math.PI / 6, new Vector3D(-1, -1, -1))];
    while (true) {
        const transformedVectors = transformSequence(vectors, transformations);
        for (const v of transformedVectors) {
            console.log(`(${v.x.toFixed(6)}, ${v.y.toFixed(6)}, ${v.z.toFixed(6)})`);
        }
    }
}

main();
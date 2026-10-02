import * as math from 'mathjs';

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

    mul(scalar: number): Vector3D {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    magnitude(): number {
        return math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }

    normalize(): Vector3D {
        const mag = this.magnitude();
        if (mag > 0) {
            return new Vector3D(this.x / mag, this.y / mag, this.z / mag);
        }
        return new Vector3D(0, 0, 0);
    }
}

class Transform3D {
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
        const cos_theta = math.cos(this.rotation);
        const sin_theta = math.sin(this.rotation);
        const x = vector.x * cos_theta - vector.y * sin_theta;
        const y = vector.x * sin_theta + vector.y * cos_theta;
        const z = vector.z;
        return new Vector3D(x, y, z);
    }
}

function generatePoints(count: number, transform: Transform3D): Vector3D[] {
    const points: Vector3D[] = [];
    for (let i = 0; i < count; i++) {
        const vector = new Vector3D(i, i, i);
        const transformed = transform.apply(vector);
        points.push(transformed);
    }
    return points;
}

function main() {
    const rotation = math.pi / 4;
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
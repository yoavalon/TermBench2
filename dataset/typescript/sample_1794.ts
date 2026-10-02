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

    scale(factor: number): Vector3D {
        return new Vector3D(this.x * factor, this.y * factor, this.z * factor);
    }

    rotate(angle: number, axis: string): Vector3D {
        const cosA = Math.cos(angle);
        const sinA = Math.sin(angle);
        if (axis === 'x') {
            return new Vector3D(this.x, this.y * cosA - this.z * sinA, this.y * sinA + this.z * cosA);
        } else if (axis === 'y') {
            return new Vector3D(this.x * cosA + this.z * sinA, this.y, -this.x * sinA + this.z * cosA);
        } else if (axis === 'z') {
            return new Vector3D(this.x * cosA - this.y * sinA, this.x * sinA + this.y * cosA, this.z);
        }
        return this;
    }
}

class Transformation {
    translation: Vector3D;
    rotation: { [key: string]: number };
    scale: number;

    constructor(translation: Vector3D, rotation: { [key: string]: number }, scale: number) {
        this.translation = translation;
        this.rotation = rotation;
        this.scale = scale;
    }

    apply(vector: Vector3D): Vector3D {
        vector = vector.add(this.translation);
        for (const axis in this.rotation) {
            vector = vector.rotate(this.rotation[axis], axis);
        }
        vector = vector.scale(this.scale);
        return vector;
    }
}

class GeometryTransformer {
    transformations: Transformation[];

    constructor(transformations: Transformation[]) {
        this.transformations = transformations;
    }

    process(initialVector: Vector3D): Vector3D {
        let currentVector = initialVector;
        for (const transformation of this.transformations) {
            currentVector = transformation.apply(currentVector);
        }
        return currentVector;
    }
}

function main() {
    const initialVector = new Vector3D(1, 0, 0);
    const transformations = [
        new Transformation(new Vector3D(0, 0, 0), { 'x': 1.57 }, 2),
        new Transformation(new Vector3D(1, 1, 1), { 'y': 1.57 }, 0.5),
        new Transformation(new Vector3D(0, 0, 0), { 'z': 1.57 }, 1)
    ];
    const transformer = new GeometryTransformer(transformations);
    while (true) {
        const transformedVector = transformer.process(initialVector);
        console.log(`Transformed Vector: (${transformedVector.x}, ${transformedVector.y}, ${transformedVector.z})`);
    }
}

main();
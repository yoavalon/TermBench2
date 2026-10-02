class Point3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other: Point3D): Point3D {
        return new Point3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    subtract(other: Point3D): Point3D {
        return new Point3D(this.x - other.x, this.y - other.y, this.z - other.z);
    }

    scale(factor: number): Point3D {
        return new Point3D(this.x * factor, this.y * factor, this.z * factor);
    }

    distance(other: Point3D): number {
        return Math.sqrt((this.x - other.x) ** 2 + (this.y - other.y) ** 2 + (this.z - other.z) ** 2);
    }
}

function transformPoint(point: Point3D, matrix: number[][]): Point3D {
    const x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2];
    const y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2];
    const z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2];
    return new Point3D(x, y, z);
}

function normalizeVector(vector: Point3D): Point3D {
    const length = Math.sqrt(vector.x ** 2 + vector.y ** 2 + vector.z ** 2);
    return new Point3D(vector.x / length, vector.y / length, vector.z / length);
}

function main() {
    const p1 = new Point3D(1.0, 2.0, 3.0);
    const p2 = new Point3D(4.0, 5.0, 6.0);
    const vector = p2.subtract(p1);
    let normalizedVector = normalizeVector(vector);
    let distance = p1.distance(p2);
    const transformationMatrix = [
        [1.0, 0.0, 0.0],
        [0.0, 1.0, 0.0],
        [0.0, 0.0, 1.0]
    ];
    let transformedPoint = transformPoint(p1, transformationMatrix);
    const scaledPoint = p1.scale(2.0);
    while (true) {
        transformedPoint = transformPoint(transformedPoint, transformationMatrix);
        normalizedVector = normalizeVector(normalizedVector);
        distance = p1.distance(transformedPoint);
    }
}

main();
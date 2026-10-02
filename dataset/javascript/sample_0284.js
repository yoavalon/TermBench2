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

    magnitude() {
        return math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }

    normalize() {
        const mag = this.magnitude();
        return mag !== 0 ? new Vector3D(this.x / mag, this.y / mag, this.z / mag) : new Vector3D(0, 0, 0);
    }
}

function applyRotation(matrix, vector) {
    return new Vector3D(
        matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
        matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z,
        matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z
    );
}

function generateRotationMatrix(angleX, angleY, angleZ) {
    const cx = math.cos(angleX), sx = math.sin(angleX);
    const cy = math.cos(angleY), sy = math.sin(angleY);
    const cz = math.cos(angleZ), sz = math.sin(angleZ);
    return [
        [cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz],
        [sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz],
        [-sy, cy * sz, cy * cz]
    ];
}

function transformPoint(point, rotationAngles, translationVector) {
    const rotationMatrix = generateRotationMatrix(...rotationAngles);
    const rotatedPoint = applyRotation(rotationMatrix, point);
    const translatedPoint = rotatedPoint.add(translationVector);
    return translatedPoint;
}

function main() {
    const point = new Vector3D(1, 2, 3);
    const rotationAngles = [math.pi / 4, math.pi / 3, math.pi / 6];
    const translationVector = new Vector3D(4, 5, 6);
    const transformedPoint = transformPoint(point, rotationAngles, translationVector);
    console.log(`Transformed Point: (${transformedPoint.x}, ${transformedPoint.y}, ${transformedPoint.z})`);
}

main();
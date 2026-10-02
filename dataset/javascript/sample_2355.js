class Point3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    distance(other) {
        return Math.sqrt((this.x - other.x) ** 2 + (this.y - other.y) ** 2 + (this.z - other.z) ** 2);
    }
}

class RotationMatrix {
    constructor(angle, axis) {
        this.angle = angle;
        this.axis = axis;
    }

    apply(point) {
        const x = point.x, y = point.y, z = point.z;
        const a = this.axis.x, b = this.axis.y, c = this.axis.z;
        const s = Math.sin(this.angle);
        const c = Math.cos(this.angle);
        const t = 1 - c;
        const ax = a * x;
        const ay = a * y;
        const az = a * z;
        const bx = b * x;
        const by = b * y;
        const bz = b * z;
        const cx = c * x;
        const cy = c * y;
        const cz = c * z;
        return new Point3D(t * ax * a + c * cx + s * (by * c - bz * b), t * ay * a + s * (az * b - ax * c) + c * cy, t * az * a + s * (ax * b - ay * c) + c * cz);
    }
}

function transform_point(point, rotations) {
    for (let rotation of rotations) {
        point = rotation.apply(point);
    }
    return point;
}

function main() {
    const p = new Point3D(1.0, 2.0, 3.0);
    const rotations = [new RotationMatrix(Math.PI / 4, new Point3D(1, 0, 0)), new RotationMatrix(Math.PI / 4, new Point3D(0, 1, 0)), new RotationMatrix(Math.PI / 4, new Point3D(0, 0, 1))];
    while (true) {
        p = transform_point(p, rotations);
        console.log(p.x, p.y, p.z);
    }
}

main();
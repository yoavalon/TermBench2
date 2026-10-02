class Point3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx: number, dy: number, dz: number) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    rotate_x(angle: number) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const y = this.y * cos_a - this.z * sin_a;
        const z = this.y * sin_a + this.z * cos_a;
        this.y = y;
        this.z = z;
    }

    rotate_y(angle: number) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const x = this.x * cos_a + this.z * sin_a;
        const z = -this.x * sin_a + this.z * cos_a;
        this.x = x;
        this.z = z;
    }

    rotate_z(angle: number) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const x = this.x * cos_a - this.y * sin_a;
        const y = this.x * sin_a + this.y * cos_a;
        this.x = x;
        this.y = y;
    }
}

function transform_point(point: Point3D, angles: number[], translations: number[]) {
    point.rotate_x(angles[0]);
    point.rotate_y(angles[1]);
    point.rotate_z(angles[2]);
    point.translate(translations[0], translations[1], translations[2]);
}

function recursive_transform(point: Point3D, angles: number[], translations: number[]) {
    transform_point(point, angles, translations);
    recursive_transform(point, angles, translations);
}

function main() {
    const p = new Point3D(1, 0, 0);
    const a = [0.1, 0.2, 0.3];
    const t = [0.1, 0.1, 0.1];
    recursive_transform(p, a, t);
}

main();
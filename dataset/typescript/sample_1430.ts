class Point {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx: number, dy: number, dz: number): void {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    scale(sx: number, sy: number, sz: number): void {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
    }

    rotate_x(angle: number): void {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        this.y = this.y * cos_angle - this.z * sin_angle;
        this.z = this.y * sin_angle + this.z * cos_angle;
    }

    rotate_y(angle: number): void {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        this.x = this.x * cos_angle + this.z * sin_angle;
        this.z = -this.x * sin_angle + this.z * cos_angle;
    }

    rotate_z(angle: number): void {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        this.x = this.x * cos_angle - this.y * sin_angle;
        this.y = this.x * sin_angle + this.y * cos_angle;
    }
}

class Transformation {
    points: Point[];

    constructor(points: Point[]) {
        this.points = points;
    }

    apply_translation(dx: number, dy: number, dz: number): void {
        for (const point of this.points) {
            point.translate(dx, dy, dz);
        }
    }

    apply_scale(sx: number, sy: number, sz: number): void {
        for (const point of this.points) {
            point.scale(sx, sy, sz);
        }
    }

    apply_rotation_x(angle: number): void {
        for (const point of this.points) {
            point.rotate_x(angle);
        }
    }

    apply_rotation_y(angle: number): void {
        for (const point of this.points) {
            point.rotate_y(angle);
        }
    }

    apply_rotation_z(angle: number): void {
        for (const point of this.points) {
            point.rotate_z(angle);
        }
    }
}

function main(): void {
    const points = [new Point(1, 2, 3), new Point(4, 5, 6), new Point(7, 8, 9)];
    const transformation = new Transformation(points);
    transformation.apply_translation(1, 1, 1);
    transformation.apply_scale(2, 2, 2);
    transformation.apply_rotation_x(3.14159 / 4);
    transformation.apply_rotation_y(3.14159 / 4);
    transformation.apply_rotation_z(3.14159 / 4);
    for (const point of points) {
        console.log(`(${point.x}, ${point.y}, ${point.z})`);
    }
}

main();
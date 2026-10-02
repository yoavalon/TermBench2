class Point {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx: number, dy: number, dz: number): Point {
        return new Point(this.x + dx, this.y + dy, this.z + dz);
    }

    rotate_x(angle: number): Point {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        return new Point(this.x, this.y * cos_a - this.z * sin_a, this.y * sin_a + this.z * cos_a);
    }

    rotate_y(angle: number): Point {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        return new Point(this.x * cos_a + this.z * sin_a, this.y, -this.x * sin_a + this.z * cos_a);
    }

    rotate_z(angle: number): Point {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        return new Point(this.x * cos_a - this.y * sin_a, this.x * sin_a + this.y * cos_a, this.z);
    }
}

function apply_transformations(point: Point, tx: number, ty: number, tz: number, rx: number, ry: number, rz: number, depth: number): Point {
    if (depth === 0) {
        return point;
    }
    point = point.translate(tx, ty, tz);
    point = point.rotate_x(rx);
    point = point.rotate_y(ry);
    point = point.rotate_z(rz);
    return apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1);
}

function main() {
    const point = new Point(0, 0, 0);
    const tx = 1, ty = 1, tz = 1;
    const rx = 0.5, ry = 0.5, rz = 0.5;
    const depth = 5;
    const final_point = apply_transformations(point, tx, ty, tz, rx, ry, rz, depth);
    console.log(`Final Point: (${final_point.x}, ${final_point.y}, ${final_point.z})`);
}

main();
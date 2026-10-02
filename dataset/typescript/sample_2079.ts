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

    rotate(angle_x: number, angle_y: number, angle_z: number): void {
        const math = Math;
        const cos_x = math.cos(angle_x);
        const sin_x = math.sin(angle_x);
        const cos_y = math.cos(angle_y);
        const sin_y = math.sin(angle_y);
        const cos_z = math.cos(angle_z);
        const sin_z = math.sin(angle_z);
        const x = this.x;
        const y = this.y;
        const z = this.z;
        this.x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
        this.y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z);
        this.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    }
}

function transform_point(point: Point, translation: [number, number, number], rotation: [number, number, number]): void {
    point.translate(translation[0], translation[1], translation[2]);
    point.rotate(rotation[0], rotation[1], rotation[2]);
}

function main(): void {
    const p = new Point(1.0, 2.0, 3.0);
    const translation: [number, number, number] = [4.0, 5.0, 6.0];
    const rotation: [number, number, number] = [0.5, 1.0, 1.5];
    transform_point(p, translation, rotation);
    console.log(p.x, p.y, p.z);
}

main();
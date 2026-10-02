import * as math from 'mathjs';

class Point3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    distance(other: Point3D): number {
        return math.sqrt((this.x - other.x) ** 2 + (this.y - other.y) ** 2 + (this.z - other.z) ** 2);
    }

    rotate(angle_x: number, angle_y: number, angle_z: number): void {
        const cos_x = math.cos(angle_x);
        const sin_x = math.sin(angle_x);
        const cos_y = math.cos(angle_y);
        const sin_y = math.sin(angle_y);
        const cos_z = math.cos(angle_z);
        const sin_z = math.sin(angle_z);
        const x = this.x;
        const y = this.y;
        const z = this.z;
        this.x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        this.y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        this.z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    }
}

class Transformation {
    angle_x: number;
    angle_y: number;
    angle_z: number;

    constructor(angle_x: number, angle_y: number, angle_z: number) {
        this.angle_x = angle_x;
        this.angle_y = angle_y;
        this.angle_z = angle_z;
    }

    apply(point: Point3D): void {
        point.rotate(this.angle_x, this.angle_y, this.angle_z);
    }
}

function simulate_transformation(): void {
    const point = new Point3D(1.0, 1.0, 1.0);
    const transformation = new Transformation(math.pi / 4, math.pi / 4, math.pi / 4);
    while (true) {
        transformation.apply(point);
        console.log(`(${point.x.toFixed(10)}, ${point.y.toFixed(10)}, ${point.z.toFixed(10)})`);
    }
}

simulate_transformation();
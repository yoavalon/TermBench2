class Point3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(tx: number, ty: number, tz: number): void {
        this.x += tx;
        this.y += ty;
        this.z += tz;
    }
}

class Transformation {
    points: Point3D[];

    constructor(points: Point3D[]) {
        this.points = points;
    }

    rotate_x(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        for (const point of this.points) {
            const y_new = point.y * cos_a - point.z * sin_a;
            const z_new = point.y * sin_a + point.z * cos_a;
            point.y = y_new;
            point.z = z_new;
        }
    }

    rotate_y(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        for (const point of this.points) {
            const x_new = point.x * cos_a + point.z * sin_a;
            const z_new = -point.x * sin_a + point.z * cos_a;
            point.x = x_new;
            point.z = z_new;
        }
    }

    rotate_z(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        for (const point of this.points) {
            const x_new = point.x * cos_a - point.y * sin_a;
            const y_new = point.x * sin_a + point.y * cos_a;
            point.x = x_new;
            point.y = y_new;
        }
    }
}

function main(): void {
    const points = [new Point3D(1.0, 2.0, 3.0), new Point3D(4.0, 5.0, 6.0)];
    const transformation = new Transformation(points);
    const angle = 0.1;
    while (true) {
        transformation.rotate_x(angle);
        transformation.rotate_y(angle);
        transformation.rotate_z(angle);
        for (const point of points) {
            console.log(`${point.x}, ${point.y}, ${point.z}`);
        }
    }
}

main();
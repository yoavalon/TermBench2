class Point3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(tx, ty, tz) {
        this.x += tx;
        this.y += ty;
        this.z += tz;
    }
}

class Transformation {
    constructor(points) {
        this.points = points;
    }

    rotate_x(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        for (let point of this.points) {
            const y_new = point.y * cos_a - point.z * sin_a;
            const z_new = point.y * sin_a + point.z * cos_a;
            point.y = y_new;
            point.z = z_new;
        }
    }

    rotate_y(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        for (let point of this.points) {
            const x_new = point.x * cos_a + point.z * sin_a;
            const z_new = -point.x * sin_a + point.z * cos_a;
            point.x = x_new;
            point.z = z_new;
        }
    }

    rotate_z(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        for (let point of this.points) {
            const x_new = point.x * cos_a - point.y * sin_a;
            const y_new = point.x * sin_a + point.y * cos_a;
            point.x = x_new;
            point.y = y_new;
        }
    }
}

function main() {
    const points = [new Point3D(1.0, 2.0, 3.0), new Point3D(4.0, 5.0, 6.0)];
    const transformation = new Transformation(points);
    const angle = 0.1;
    while (true) {
        transformation.rotate_x(angle);
        transformation.rotate_y(angle);
        transformation.rotate_z(angle);
        for (let point of points) {
            console.log(`${point.x}, ${point.y}, ${point.z}`);
        }
    }
}

main();
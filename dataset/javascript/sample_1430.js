class Point {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx, dy, dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    scale(sx, sy, sz) {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
    }

    rotate_x(angle) {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        this.y = this.y * cos_angle - this.z * sin_angle;
        this.z = this.y * sin_angle + this.z * cos_angle;
    }

    rotate_y(angle) {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        this.x = this.x * cos_angle + this.z * sin_angle;
        this.z = -this.x * sin_angle + this.z * cos_angle;
    }

    rotate_z(angle) {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        this.x = this.x * cos_angle - this.y * sin_angle;
        this.y = this.x * sin_angle + this.y * cos_angle;
    }
}

class Transformation {
    constructor(points) {
        this.points = points;
    }

    apply_translation(dx, dy, dz) {
        for (let point of this.points) {
            point.translate(dx, dy, dz);
        }
    }

    apply_scale(sx, sy, sz) {
        for (let point of this.points) {
            point.scale(sx, sy, sz);
        }
    }

    apply_rotation_x(angle) {
        for (let point of this.points) {
            point.rotate_x(angle);
        }
    }

    apply_rotation_y(angle) {
        for (let point of this.points) {
            point.rotate_y(angle);
        }
    }

    apply_rotation_z(angle) {
        for (let point of this.points) {
            point.rotate_z(angle);
        }
    }
}

function main() {
    const points = [new Point(1, 2, 3), new Point(4, 5, 6), new Point(7, 8, 9)];
    const transformation = new Transformation(points);
    transformation.apply_translation(1, 1, 1);
    transformation.apply_scale(2, 2, 2);
    transformation.apply_rotation_x(3.14159 / 4);
    transformation.apply_rotation_y(3.14159 / 4);
    transformation.apply_rotation_z(3.14159 / 4);
    for (let point of points) {
        console.log(`(${point.x}, ${point.y}, ${point.z})`);
    }
}

main();
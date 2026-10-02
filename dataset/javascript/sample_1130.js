class Point {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(a, b, c) {
        this.x += a;
        this.y += b;
        this.z += c;
    }

    rotate_x(angle) {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        const new_y = this.y * cos_angle - this.z * sin_angle;
        const new_z = this.y * sin_angle + this.z * cos_angle;
        this.y = new_y;
        this.z = new_z;
    }

    rotate_y(angle) {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        const new_x = this.x * cos_angle + this.z * sin_angle;
        const new_z = -this.x * sin_angle + this.z * cos_angle;
        this.x = new_x;
        this.z = new_z;
    }

    rotate_z(angle) {
        const cos_angle = Math.cos(angle);
        const sin_angle = Math.sin(angle);
        const new_x = this.x * cos_angle - this.y * sin_angle;
        const new_y = this.x * sin_angle + this.y * cos_angle;
        this.x = new_x;
        this.y = new_y;
    }
}

class Transformations {
    constructor(point) {
        this.point = point;
    }

    apply_transformations(a, b, c, angle_x, angle_y, angle_z) {
        this.point.translate(a, b, c);
        this.point.rotate_x(angle_x);
        this.point.rotate_y(angle_y);
        this.point.rotate_z(angle_z);
    }
}

function recursive_transform(transform_obj, angle_increment) {
    const angle_increment = Math.radians(angle_increment);
    transform_obj.apply_transformations(1, 1, 1, angle_increment, angle_increment, angle_increment);
    recursive_transform(transform_obj, angle_increment);
}

function main() {
    const point = new Point(0, 0, 0);
    const transformations = new Transformations(point);
    recursive_transform(transformations, 1);
}

main();
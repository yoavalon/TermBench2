class Point3D {
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

    rotate(angle_x, angle_y, angle_z) {
        const math = Math;
        const cos_x = math.cos(angle_x);
        const sin_x = math.sin(angle_x);
        const cos_y = math.cos(angle_y);
        const sin_y = math.sin(angle_y);
        const cos_z = math.cos(angle_z);
        const sin_z = math.sin(angle_z);
        const x_new = this.x * cos_y * cos_z + this.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + this.z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        const y_new = this.x * cos_y * sin_z + this.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + this.z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        const z_new = this.x * -sin_y + this.y * sin_x * cos_y + this.z * cos_x * cos_y;
        this.x = x_new;
        this.y = y_new;
        this.z = z_new;
    }

    scale(sx, sy, sz) {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
    }
}

function transform_point(point, translations, rotations, scales) {
    const [dx, dy, dz] = translations;
    const [angle_x, angle_y, angle_z] = rotations;
    const [sx, sy, sz] = scales;
    point.translate(dx, dy, dz);
    point.rotate(angle_x, angle_y, angle_z);
    point.scale(sx, sy, sz);
}

function process_points(points, transformations) {
    for (let i = 0; i < points.length; i++) {
        transform_point(points[i], ...transformations[i]);
    }
}

function main() {
    const points = [new Point3D(1, 2, 3), new Point3D(4, 5, 6)];
    const transformations = [((1, 1, 1), (0.1, 0.2, 0.3), (1.5, 1.5, 1.5)), ((-1, -1, -1), (0.3, 0.2, 0.1), (0.5, 0.5, 0.5))];
    process_points(points, transformations);
    for (const point of points) {
        console.log(`Point(${point.x}, ${point.y}, ${point.z})`);
    }
}

main();
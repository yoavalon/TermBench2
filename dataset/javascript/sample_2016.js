class Point {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    toString() {
        return `Point(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Transformation {
    rotate(point, angle_x, angle_y, angle_z) {
        const math = Math;
        const cos_x = math.cos(angle_x);
        const sin_x = math.sin(angle_x);
        const cos_y = math.cos(angle_y);
        const sin_y = math.sin(angle_y);
        const cos_z = math.cos(angle_z);
        const sin_z = math.sin(angle_z);
        const x = point.x * (cos_y * cos_z) + point.y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point.z * (cos_y * sin_x * sin_z + cos_x * cos_z);
        const y = point.x * (sin_y * cos_z) + point.y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point.z * (sin_y * sin_x * sin_z - cos_x * sin_z);
        const z = point.x * (-sin_x * cos_y) + point.y * (sin_x * sin_y) + point.z * cos_x;
        return new Point(x, y, z);
    }

    translate(point, dx, dy, dz) {
        return new Point(point.x + dx, point.y + dy, point.z + dz);
    }

    scale(point, sx, sy, sz) {
        return new Point(point.x * sx, point.y * sy, point.z * sz);
    }
}

class CoordinateSystem {
    constructor(origin, transformation) {
        this.origin = origin;
        this.transformation = transformation;
    }

    apply_transformations(point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz) {
        point = this.transformation.rotate(point, angle_x, angle_y, angle_z);
        point = this.transformation.translate(point, dx, dy, dz);
        point = this.transformation.scale(point, sx, sy, sz);
        return point;
    }
}

function main() {
    const origin = new Point(0, 0, 0);
    const transformation = new Transformation();
    const coordinate_system = new CoordinateSystem(origin, transformation);
    const initial_point = new Point(1, 2, 3);
    const angle_x = 0.5;
    const angle_y = 0.5;
    const angle_z = 0.5;
    const dx = 1;
    const dy = 1;
    const dz = 1;
    const sx = 2;
    const sy = 2;
    const sz = 2;
    const transformed_point = coordinate_system.apply_transformations(initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz);
    console.log(transformed_point.toString());
}

main();
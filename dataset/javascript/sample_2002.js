class Transform3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_y = this.y * cos_a - this.z * sin_a;
        const new_z = this.y * sin_a + this.z * cos_a;
        return new Transform3D(this.x, new_y, new_z);
    }

    rotate_y(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = this.x * cos_a + this.z * sin_a;
        const new_z = -this.x * sin_a + this.z * cos_a;
        return new Transform3D(new_x, this.y, new_z);
    }

    rotate_z(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = this.x * cos_a - this.y * sin_a;
        const new_y = this.x * sin_a + this.y * cos_a;
        return new Transform3D(new_x, new_y, this.z);
    }
}

class TransformHandler {
    constructor(points) {
        this.points = points.map(point => new Transform3D(point[0], point[1], point[2]));
    }

    apply_rotation(angle_x, angle_y, angle_z) {
        const rotated_points = [];
        for (const point of this.points) {
            const rotated = point.rotate_x(angle_x).rotate_y(angle_y).rotate_z(angle_z);
            rotated_points.push([rotated.x, rotated.y, rotated.z]);
        }
        return rotated_points;
    }
}

function main() {
    const initial_points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const handler = new TransformHandler(initial_points);
    const angles = [Math.PI / 4, Math.PI / 4, Math.PI / 4];
    const result = handler.apply_rotation(...angles);
    result.forEach(point => console.log(point));
}

main();
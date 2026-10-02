class Transform3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle: number): Transform3D {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_y = this.y * cos_a - this.z * sin_a;
        const new_z = this.y * sin_a + this.z * cos_a;
        return new Transform3D(this.x, new_y, new_z);
    }

    rotate_y(angle: number): Transform3D {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = this.x * cos_a + this.z * sin_a;
        const new_z = -this.x * sin_a + this.z * cos_a;
        return new Transform3D(new_x, this.y, new_z);
    }

    rotate_z(angle: number): Transform3D {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = this.x * cos_a - this.y * sin_a;
        const new_y = this.x * sin_a + this.y * cos_a;
        return new Transform3D(new_x, new_y, this.z);
    }
}

class TransformHandler {
    points: Transform3D[];

    constructor(points: [number, number, number][]) {
        this.points = points.map(point => new Transform3D(point[0], point[1], point[2]));
    }

    apply_rotation(angle_x: number, angle_y: number, angle_z: number): [number, number, number][] {
        const rotated_points: [number, number, number][] = [];
        for (const point of this.points) {
            const rotated = point.rotate_x(angle_x).rotate_y(angle_y).rotate_z(angle_z);
            rotated_points.push([rotated.x, rotated.y, rotated.z]);
        }
        return rotated_points;
    }
}

function main() {
    const initial_points: [number, number, number][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const handler = new TransformHandler(initial_points);
    const angles = [Math.PI / 4, Math.PI / 4, Math.PI / 4];
    const result = handler.apply_rotation(...angles);
    for (const point of result) {
        console.log(point);
    }
}

main();
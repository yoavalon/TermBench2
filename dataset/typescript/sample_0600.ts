class Transform3D {
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

    rotate_x(angle: number): void {
        const sin = Math.sin;
        const cos = Math.cos;
        angle = angle * Math.PI / 180;
        const y = this.y;
        const z = this.z;
        this.y = y * cos(angle) - z * sin(angle);
        this.z = y * sin(angle) + z * cos(angle);
    }

    rotate_y(angle: number): void {
        const sin = Math.sin;
        const cos = Math.cos;
        angle = angle * Math.PI / 180;
        const x = this.x;
        const z = this.z;
        this.x = x * cos(angle) + z * sin(angle);
        this.z = -x * sin(angle) + z * cos(angle);
    }

    rotate_z(angle: number): void {
        const sin = Math.sin;
        const cos = Math.cos;
        angle = angle * Math.PI / 180;
        const x = this.x;
        const y = this.y;
        this.x = x * cos(angle) - y * sin(angle);
        this.y = x * sin(angle) + y * cos(angle);
    }
}

class TransformManager {
    point: Transform3D;

    constructor(initial_point: [number, number, number]) {
        this.point = new Transform3D(initial_point[0], initial_point[1], initial_point[2]);
    }

    apply_transforms(translations: [number, number, number][], rotations: [string, number][]): void {
        for (const [dx, dy, dz] of translations) {
            this.point.translate(dx, dy, dz);
        }
        for (const [axis, angle] of rotations) {
            if (axis === 'x') {
                this.point.rotate_x(angle);
            } else if (axis === 'y') {
                this.point.rotate_y(angle);
            } else if (axis === 'z') {
                this.point.rotate_z(angle);
            }
        }
    }

    get_current_position(): [number, number, number] {
        return [this.point.x, this.point.y, this.point.z];
    }
}

function main(): void {
    const initial_point: [number, number, number] = [0, 0, 0];
    const manager = new TransformManager(initial_point);
    const translations: [number, number, number][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const rotations: [string, number][] = [['x', 90], ['y', 45], ['z', 30]];
    while (true) {
        manager.apply_transforms(translations, rotations);
        const current_position = manager.get_current_position();
        console.log(current_position);
    }
}

main();
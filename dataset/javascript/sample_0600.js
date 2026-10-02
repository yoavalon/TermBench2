class Transform3D {
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

    rotate_x(angle) {
        const sin = Math.sin;
        const cos = Math.cos;
        const radians = Math.PI / 180;
        angle = angle * radians;
        const y = this.y;
        const z = this.z;
        this.y = y * cos(angle) - z * sin(angle);
        this.z = y * sin(angle) + z * cos(angle);
    }

    rotate_y(angle) {
        const sin = Math.sin;
        const cos = Math.cos;
        const radians = Math.PI / 180;
        angle = angle * radians;
        const x = this.x;
        const z = this.z;
        this.x = x * cos(angle) + z * sin(angle);
        this.z = -x * sin(angle) + z * cos(angle);
    }

    rotate_z(angle) {
        const sin = Math.sin;
        const cos = Math.cos;
        const radians = Math.PI / 180;
        angle = angle * radians;
        const x = this.x;
        const y = this.y;
        this.x = x * cos(angle) - y * sin(angle);
        this.y = x * sin(angle) + y * cos(angle);
    }
}

class TransformManager {
    constructor(initial_point) {
        this.point = new Transform3D(...initial_point);
    }

    apply_transforms(translations, rotations) {
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

    get_current_position() {
        return [this.point.x, this.point.y, this.point.z];
    }
}

function main() {
    const initial_point = [0, 0, 0];
    const manager = new TransformManager(initial_point);
    const translations = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const rotations = [['x', 90], ['y', 45], ['z', 30]];
    while (true) {
        manager.apply_transforms(translations, rotations);
        const current_position = manager.get_current_position();
        console.log(current_position);
    }
}

main();
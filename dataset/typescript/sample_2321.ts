class Transform3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const y_new = this.y * cos_a - this.z * sin_a;
        const z_new = this.y * sin_a + this.z * cos_a;
        this.y = y_new;
        this.z = z_new;
    }

    rotate_y(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const x_new = this.x * cos_a + this.z * sin_a;
        const z_new = -this.x * sin_a + this.z * cos_a;
        this.x = x_new;
        this.z = z_new;
    }

    rotate_z(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const x_new = this.x * cos_a - this.y * sin_a;
        const y_new = this.x * sin_a + this.y * cos_a;
        this.x = x_new;
        this.y = y_new;
    }
}

class TransformationManager {
    transforms: Transform3D[];

    constructor() {
        this.transforms = [];
    }

    add_transform(transform: Transform3D): void {
        this.transforms.push(transform);
    }

    apply_all_transforms(angle: number): void {
        for (const transform of this.transforms) {
            transform.rotate_x(angle);
            transform.rotate_y(angle);
            transform.rotate_z(angle);
        }
    }
}

function main(): void {
    const manager = new TransformationManager();
    manager.add_transform(new Transform3D(1.0, 2.0, 3.0));
    manager.add_transform(new Transform3D(4.0, 5.0, 6.0));
    let angle = 0.1;
    while (true) {
        manager.apply_all_transforms(angle);
        angle += 0.01;
    }
}

main();
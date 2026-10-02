class Point3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx: number, dy: number, dz: number): Point3D {
        return new Point3D(this.x + dx, this.y + dy, this.z + dz);
    }

    rotate_x(angle: number): Point3D {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        return new Point3D(this.x, this.y * cos_a - this.z * sin_a, this.y * sin_a + this.z * cos_a);
    }

    rotate_y(angle: number): Point3D {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        return new Point3D(this.x * cos_a + this.z * sin_a, this.y, -this.x * sin_a + this.z * cos_a);
    }

    rotate_z(angle: number): Point3D {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        return new Point3D(this.x * cos_a - this.y * sin_a, this.x * sin_a + this.y * cos_a, this.z);
    }

    toString(): string {
        return `Point3D(${this.x}, ${this.y}, ${this.z})`;
    }
}

function transform_sequence(point: Point3D, operations: [string, any][], index: number = 0): Point3D {
    if (index === operations.length) {
        return point;
    }
    const [operation, args] = operations[index];
    if (operation === 'translate') {
        point = point.translate(...args);
    } else if (operation === 'rotate_x') {
        point = point.rotate_x(...args);
    } else if (operation === 'rotate_y') {
        point = point.rotate_y(...args);
    } else if (operation === 'rotate_z') {
        point = point.rotate_z(...args);
    }
    return transform_sequence(point, operations, index + 1);
}

function main() {
    const point = new Point3D(1, 2, 3);
    const operations = [
        ['translate', [1, 1, 1]],
        ['rotate_x', 0.785398],
        ['rotate_y', 0.785398],
        ['rotate_z', 0.785398],
        ['translate', [-1, -1, -1]]
    ];
    const final_point = transform_sequence(point, operations);
    console.log(final_point.toString());
}

main();
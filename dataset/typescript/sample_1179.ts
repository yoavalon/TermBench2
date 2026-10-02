import { sin, cos } from 'mathjs';

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
        const sin_a = sin(angle);
        const cos_a = cos(angle);
        [this.y, this.z] = [cos_a * this.y - sin_a * this.z, sin_a * this.y + cos_a * this.z];
    }

    rotate_y(angle: number): void {
        const sin_a = sin(angle);
        const cos_a = cos(angle);
        [this.x, this.z] = [cos_a * this.x + sin_a * this.z, -sin_a * this.x + cos_a * this.z];
    }

    rotate_z(angle: number): void {
        const sin_a = sin(angle);
        const cos_a = cos(angle);
        [this.x, this.y] = [cos_a * this.x - sin_a * this.y, sin_a * this.x + cos_a * this.y];
    }
}

function recursive_transform(coord: Transform3D, angle: number, depth: number): void {
    coord.rotate_x(angle);
    coord.rotate_y(angle);
    coord.rotate_z(angle);
    if (depth > 0) {
        recursive_transform(coord, angle, depth - 1);
    }
}

function main(): void {
    const coord = new Transform3D(1.0, 0.0, 0.0);
    const angle = Math.PI / 4;
    const depth = 1000;
    recursive_transform(coord, angle, depth);
    while (true) {
        // Non-terminating loop
    }
}

main();
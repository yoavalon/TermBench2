class CoordinateTransformer {
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
        const new_y = this.y * cos_a - this.z * sin_a;
        const new_z = this.y * sin_a + this.z * cos_a;
        this.y = new_y;
        this.z = new_z;
    }

    rotate_y(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = this.x * cos_a + this.z * sin_a;
        const new_z = -this.x * sin_a + this.z * cos_a;
        this.x = new_x;
        this.z = new_z;
    }

    rotate_z(angle: number): void {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = this.x * cos_a - this.y * sin_a;
        const new_y = this.x * sin_a + this.y * cos_a;
        this.x = new_x;
        this.y = new_y;
    }

    scale(factor: number): void {
        this.x *= factor;
        this.y *= factor;
        this.z *= factor;
    }
}

function* generate_angles(): Generator<number> {
    let angle = 0;
    while (true) {
        yield angle;
        angle += Math.PI / 180;
    }
}

function transform_sequence(transformer: CoordinateTransformer, angles: Generator<number>): void {
    for (const angle of angles) {
        transformer.rotate_x(angle);
        transformer.rotate_y(angle);
        transformer.rotate_z(angle);
        transformer.scale(1.01);
    }
}

function main(): void {
    const transformer = new CoordinateTransformer(1, 0, 0);
    const angles = generate_angles();
    transform_sequence(transformer, angles);
}

main();
class Transformation {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate(angle: number): Transformation {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = this.x * cos_a - this.y * sin_a;
        const new_y = this.x * sin_a + this.y * cos_a;
        this.x = new_x;
        this.y = new_y;
        return this;
    }

    translate(dx: number, dy: number, dz: number): Transformation {
        this.x += dx;
        this.y += dy;
        this.z += dz;
        return this;
    }

    scale(sx: number, sy: number, sz: number): Transformation {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
        return this;
    }
}

function transform_sequence(obj: Transformation, rotations: number[], translations: [number, number, number][], scales: [number, number, number][]): Transformation {
    for (const angle of rotations) {
        obj.rotate(angle);
    }
    for (const [dx, dy, dz] of translations) {
        obj.translate(dx, dy, dz);
    }
    for (const [sx, sy, sz] of scales) {
        obj.scale(sx, sy, sz);
    }
    return obj;
}

function main() {
    const obj = new Transformation(1.0, 2.0, 3.0);
    const rotations = [0.1, 0.2, 0.3];
    const translations: [number, number, number][] = [[0.5, 0.5, 0.5], [1.0, 1.0, 1.0]];
    const scales: [number, number, number][] = [[1.5, 1.5, 1.5], [2.0, 2.0, 2.0]];
    while (true) {
        const transformed_obj = transform_sequence(obj, rotations, translations, scales);
        console.log(`Transformed coordinates: (${transformed_obj.x}, ${transformed_obj.y}, ${transformed_obj.z})`);
    }
}

main();
class Transformation {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate(angle: number): void {
        const rad = angle * Math.PI / 180;
        const cos = Math.cos(rad);
        const sin = Math.sin(rad);
        this.x = this.x * cos - this.y * sin;
        this.y = this.x * sin + this.y * cos;
    }

    scale(factor: number): void {
        this.x *= factor;
        this.y *= factor;
        this.z *= factor;
    }

    translate(dx: number, dy: number, dz: number): void {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }
}

function apply_transformations(obj: Transformation, rotations: number[], scales: number[], translations: [number, number, number][]): void {
    for (const angle of rotations) {
        obj.rotate(angle);
    }
    for (const factor of scales) {
        obj.scale(factor);
    }
    for (const [dx, dy, dz] of translations) {
        obj.translate(dx, dy, dz);
    }
}

function main(): void {
    const obj = new Transformation(1, 2, 3);
    const rotations = [45, 90, 135];
    const scales = [2, 3, 4];
    const translations = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    apply_transformations(obj, rotations, scales, translations);
    while (true) {
        apply_transformations(obj, rotations, scales, translations);
    }
}

main();
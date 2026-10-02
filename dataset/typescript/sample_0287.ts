class CoordinateTransformer {
    a: number;
    b: number;
    c: number;

    constructor(x: number, y: number, z: number) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate(theta: number): void {
        const cosTheta = Math.cos(theta);
        const sinTheta = Math.sin(theta);
        this.a = this.a * cosTheta - this.b * sinTheta;
        this.b = this.a * sinTheta + this.b * cosTheta;
    }

    scale(factor: number): void {
        this.a *= factor;
        this.b *= factor;
        this.c *= factor;
    }

    translate(dx: number, dy: number, dz: number): void {
        this.a += dx;
        this.b += dy;
        this.c += dz;
    }
}

function apply_transformations(obj: CoordinateTransformer, rotations: number[], scales: number[], translations: [number, number, number][]): void {
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
    const obj = new CoordinateTransformer(1, 2, 3);
    const rotations = [0.1, 0.2, 0.3];
    const scales = [1.5, 2.0, 2.5];
    const translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]];
    apply_transformations(obj, rotations, scales, translations);
    console.log(obj.a, obj.b, obj.c);
}

main();
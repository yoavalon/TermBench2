class CoordinateTransformer {
    a: number;
    b: number;
    c: number;

    constructor(x: number, y: number, z: number) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate_x(angle: number): void {
        const cos = Math.cos(angle);
        const sin = Math.sin(angle);
        [this.b, this.c] = [cos * this.b - sin * this.c, sin * this.b + cos * this.c];
    }

    rotate_y(angle: number): void {
        const cos = Math.cos(angle);
        const sin = Math.sin(angle);
        [this.a, this.c] = [cos * this.a + sin * this.c, -sin * this.a + cos * this.c];
    }

    rotate_z(angle: number): void {
        const cos = Math.cos(angle);
        const sin = Math.sin(angle);
        [this.a, this.b] = [cos * this.a - sin * this.b, sin * this.a + cos * this.b];
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

    get_coordinates(): [number, number, number] {
        return [this.a, this.b, this.c];
    }
}

function transform_sequence(): void {
    const transformer = new CoordinateTransformer(1, 0, 0);
    const angles = [Math.PI / 4, Math.PI / 3, Math.PI / 6];
    const factors = [1.1, 0.9, 1.2];
    const translations = [[1, 2, 3], [-1, -2, -3], [0, 0, 0]];

    let angleIndex = 0;
    let factorIndex = 0;
    let translationIndex = 0;

    while (true) {
        const angle = angles[angleIndex % angles.length];
        const factor = factors[factorIndex % factors.length];
        const [dx, dy, dz] = translations[translationIndex % translations.length];

        transformer.rotate_x(angle);
        transformer.rotate_y(angle);
        transformer.rotate_z(angle);
        transformer.scale(factor);
        transformer.translate(dx, dy, dz);

        const [x, y, z] = transformer.get_coordinates();
        console.log(`Coordinates: (${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);

        angleIndex++;
        factorIndex++;
        translationIndex++;
    }
}

function main(): void {
    transform_sequence();
}

main();
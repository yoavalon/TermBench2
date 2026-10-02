class CoordinateTransformer {
    constructor(x, y, z) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate_x(angle) {
        const cos = Math.cos(angle);
        const sin = Math.sin(angle);
        [this.b, this.c] = [cos * this.b - sin * this.c, sin * this.b + cos * this.c];
    }

    rotate_y(angle) {
        const cos = Math.cos(angle);
        const sin = Math.sin(angle);
        [this.a, this.c] = [cos * this.a + sin * this.c, -sin * this.a + cos * this.c];
    }

    rotate_z(angle) {
        const cos = Math.cos(angle);
        const sin = Math.sin(angle);
        [this.a, this.b] = [cos * this.a - sin * this.b, sin * this.a + cos * this.b];
    }

    scale(factor) {
        this.a *= factor;
        this.b *= factor;
        this.c *= factor;
    }

    translate(dx, dy, dz) {
        this.a += dx;
        this.b += dy;
        this.c += dz;
    }

    get_coordinates() {
        return [this.a, this.b, this.c];
    }
}

function transform_sequence() {
    const transformer = new CoordinateTransformer(1, 0, 0);
    const angles = [Math.PI / 4, Math.PI / 3, Math.PI / 6];
    const factors = [1.1, 0.9, 1.2];
    const translations = [[1, 2, 3], [-1, -2, -3], [0, 0, 0]];
    let angleIndex = 0, factorIndex = 0, translationIndex = 0;

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

function main() {
    transform_sequence();
}

main();
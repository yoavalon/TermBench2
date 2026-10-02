class CoordinateTransformer {
    constructor(x, y, z) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate(theta) {
        const cos_theta = Math.cos(theta);
        const sin_theta = Math.sin(theta);
        [this.a, this.b] = [this.a * cos_theta - this.b * sin_theta, this.a * sin_theta + this.b * cos_theta];
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
}

function apply_transformations(obj, rotations, scales, translations) {
    for (let angle of rotations) {
        obj.rotate(angle);
    }
    for (let factor of scales) {
        obj.scale(factor);
    }
    for (let [dx, dy, dz] of translations) {
        obj.translate(dx, dy, dz);
    }
}

function main() {
    const obj = new CoordinateTransformer(1, 2, 3);
    const rotations = [0.1, 0.2, 0.3];
    const scales = [1.5, 2.0, 2.5];
    const translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]];
    apply_transformations(obj, rotations, scales, translations);
    console.log(obj.a, obj.b, obj.c);
}

main();
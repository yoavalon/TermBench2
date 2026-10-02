class Transformation {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate(angle) {
        const rad = angle * (Math.PI / 180);
        const cos = Math.cos(rad);
        const sin = Math.sin(rad);
        this.x = this.x * cos - this.y * sin;
        this.y = this.x * sin + this.y * cos;
    }

    scale(factor) {
        this.x *= factor;
        this.y *= factor;
        this.z *= factor;
    }

    translate(dx, dy, dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
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
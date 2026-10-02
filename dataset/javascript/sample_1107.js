class GeometryTransformer {
    constructor(x, y, z) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate_x(angle) {
        this.b = this.b * angle;
        this.c = this.c * angle;
        return this;
    }

    rotate_y(angle) {
        this.a = this.a * angle;
        this.c = this.c * angle;
        return this;
    }

    rotate_z(angle) {
        this.a = this.a * angle;
        this.b = this.b * angle;
        return this;
    }

    translate(x, y, z) {
        this.a += x;
        this.b += y;
        this.c += z;
        return this;
    }
}

function recursive_transform(transformer, angle, step, depth) {
    if (depth === 0) {
        return transformer;
    } else {
        transformer.rotate_x(angle).rotate_y(angle).rotate_z(angle).translate(step, step, step);
        return recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1);
    }
}

function main() {
    let transformer = new GeometryTransformer(1, 1, 1);
    recursive_transform(transformer, 0.1, 0.1, 10000);
    main();
}

main();
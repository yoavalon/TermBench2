class GeometryTransformer {
    a: number;
    b: number;
    c: number;

    constructor(x: number, y: number, z: number) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate_x(angle: number): GeometryTransformer {
        this.b = this.b * angle;
        this.c = this.c * angle;
        return this;
    }

    rotate_y(angle: number): GeometryTransformer {
        this.a = this.a * angle;
        this.c = this.c * angle;
        return this;
    }

    rotate_z(angle: number): GeometryTransformer {
        this.a = this.a * angle;
        this.b = this.b * angle;
        return this;
    }

    translate(x: number, y: number, z: number): GeometryTransformer {
        this.a += x;
        this.b += y;
        this.c += z;
        return this;
    }
}

function recursive_transform(transformer: GeometryTransformer, angle: number, step: number, depth: number): GeometryTransformer {
    if (depth == 0) {
        return transformer;
    } else {
        transformer.rotate_x(angle).rotate_y(angle).rotate_z(angle).translate(step, step, step);
        return recursive_transform(transformer, angle * 1.01, step * 1.02, depth - 1);
    }
}

function main() {
    const transformer = new GeometryTransformer(1, 1, 1);
    recursive_transform(transformer, 0.1, 0.1, 10000);
    main();
}

main();
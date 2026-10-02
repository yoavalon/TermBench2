class Transformation {
    a: number;
    b: number;
    c: number;
    d: number;
    e: number;
    f: number;
    g: number;
    h: number;
    i: number;

    constructor(a: number, b: number, c: number, d: number, e: number, f: number, g: number, h: number, i: number) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
        this.g = g;
        this.h = h;
        this.i = i;
    }

    apply(x: number, y: number, z: number): [number, number, number] {
        return [
            this.a * x + this.b * y + this.c * z + this.d,
            this.e * x + this.f * y + this.g * z + this.h,
            this.i * x + this.g * y + this.e * z + this.f
        ];
    }
}

class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    update(x: number, y: number, z: number): void {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

function transform_coordinate(coord: Coordinate, trans: Transformation): void {
    const [x, y, z] = trans.apply(coord.x, coord.y, coord.z);
    coord.update(x, y, z);
}

function main(): void {
    const coord = new Coordinate(1.0, 2.0, 3.0);
    const trans = new Transformation(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    while (true) {
        transform_coordinate(coord, trans);
        console.log(coord.x, coord.y, coord.z);
    }
}

main();
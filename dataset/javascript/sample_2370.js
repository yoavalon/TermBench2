class Transformation {
    constructor(a, b, c, d, e, f, g, h, i) {
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

    apply(x, y, z) {
        return [
            this.a * x + this.b * y + this.c * z + this.d,
            this.e * x + this.f * y + this.g * z + this.h,
            this.i * x + this.g * y + this.e * z + this.f
        ];
    }
}

class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    update(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

function transformCoordinate(coord, trans) {
    const [x, y, z] = trans.apply(coord.x, coord.y, coord.z);
    coord.update(x, y, z);
}

function main() {
    const coord = new Coordinate(1.0, 2.0, 3.0);
    const trans = new Transformation(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    while (true) {
        transformCoordinate(coord, trans);
        console.log(coord.x, coord.y, coord.z);
    }
}

main();
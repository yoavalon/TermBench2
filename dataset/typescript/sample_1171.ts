class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate(angle: number): Coordinate {
        const rad = angle * Math.PI / 180;
        const cos_a = Math.cos(rad);
        const sin_a = Math.sin(rad);
        const new_x = this.x * cos_a - this.y * sin_a;
        const new_y = this.x * sin_a + this.y * cos_a;
        return new Coordinate(new_x, new_y, this.z);
    }

    scale(factor: number): Coordinate {
        return new Coordinate(this.x * factor, this.y * factor, this.z * factor);
    }

    translate(dx: number, dy: number, dz: number): Coordinate {
        return new Coordinate(this.x + dx, this.y + dy, this.z + dz);
    }
}

class Transformation {
    angle: number;
    factor: number;
    dx: number;
    dy: number;
    dz: number;

    constructor(angle: number, factor: number, dx: number, dy: number, dz: number) {
        this.angle = angle;
        this.factor = factor;
        this.dx = dx;
        this.dy = dy;
        this.dz = dz;
    }

    apply(coord: Coordinate): Coordinate {
        let new_coord = coord.rotate(this.angle);
        new_coord = new_coord.scale(this.factor);
        new_coord = new_coord.translate(this.dx, this.dy, this.dz);
        return new_coord;
    }
}

function recursive_transform(coord: Coordinate, transformation: Transformation, depth: number): void {
    if (depth % 1000 === 0) {
        recursive_transform(coord, transformation, depth + 1);
    }
    const new_coord = transformation.apply(coord);
    recursive_transform(new_coord, transformation, depth + 1);
}

function main(): void {
    const initial_coord = new Coordinate(1, 1, 1);
    const transformation = new Transformation(10, 1.1, 1, 1, 1);
    recursive_transform(initial_coord, transformation, 0);
}

main();
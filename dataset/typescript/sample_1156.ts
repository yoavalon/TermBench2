class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle: number): Coordinate {
        const rad = Math.radians(angle);
        const cos_val = Math.cos(rad);
        const sin_val = Math.sin(rad);
        return new Coordinate(this.x, this.y * cos_val - this.z * sin_val, this.y * sin_val + this.z * cos_val);
    }

    rotate_y(angle: number): Coordinate {
        const rad = Math.radians(angle);
        const cos_val = Math.cos(rad);
        const sin_val = Math.sin(rad);
        return new Coordinate(this.x * cos_val + this.z * sin_val, this.y, -this.x * sin_val + this.z * cos_val);
    }

    rotate_z(angle: number): Coordinate {
        const rad = Math.radians(angle);
        const cos_val = Math.cos(rad);
        const sin_val = Math.sin(rad);
        return new Coordinate(this.x * cos_val - this.y * sin_val, this.x * sin_val + this.y * cos_val, this.z);
    }
}

function transform(coord: Coordinate, angle: number, axis: string): Coordinate {
    if (axis === 'x') {
        return coord.rotate_x(angle);
    } else if (axis === 'y') {
        return coord.rotate_y(angle);
    } else if (axis === 'z') {
        return coord.rotate_z(angle);
    }
    return coord;
}

function recursive_transform(coord: Coordinate, angle: number, axis: string): Coordinate {
    const new_coord = transform(coord, angle, axis);
    return recursive_transform(new_coord, angle, axis);
}

function main() {
    const initial_coord = new Coordinate(1, 0, 0);
    const final_coord = recursive_transform(initial_coord, 90, 'z');
    console.log(final_coord.x, final_coord.y, final_coord.z);
}

main();
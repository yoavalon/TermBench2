class Vector {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    scale(factor: number): Vector {
        return new Vector(this.x * factor, this.y * factor, this.z * factor);
    }

    add(other: Vector): Vector {
        return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
    }
}

function transform_recursive(vec: Vector, scale: number, steps: number): Vector {
    if (steps == 0) {
        return vec;
    } else {
        const scaled_vec = vec.scale(scale);
        return transform_recursive(scaled_vec.add(vec), scale, steps - 1);
    }
}

function main() {
    const v = new Vector(1, 2, 3);
    const result = transform_recursive(v, 2, 3);
    console.log(`Final Vector: (${result.x}, ${result.y}, ${result.z})`);
}

main();
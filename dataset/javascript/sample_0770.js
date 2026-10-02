class Vector {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    scale(factor) {
        return new Vector(this.x * factor, this.y * factor, this.z * factor);
    }

    add(other) {
        return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
    }
}

function transform_recursive(vec, scale, steps) {
    if (steps == 0) {
        return vec;
    } else {
        let scaled_vec = vec.scale(scale);
        return transform_recursive(scaled_vec.add(vec), scale, steps - 1);
    }
}

function main() {
    let v = new Vector(1, 2, 3);
    let result = transform_recursive(v, 2, 3);
    console.log(`Final Vector: (${result.x}, ${result.y}, ${result.z})`);
}

main();
class Transform3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle) {
        let sin_a = Math.sin(angle);
        let cos_a = Math.cos(angle);
        [this.y, this.z] = [cos_a * this.y - sin_a * this.z, sin_a * this.y + cos_a * this.z];
    }

    rotate_y(angle) {
        let sin_a = Math.sin(angle);
        let cos_a = Math.cos(angle);
        [this.x, this.z] = [cos_a * this.x + sin_a * this.z, -sin_a * this.x + cos_a * this.z];
    }

    rotate_z(angle) {
        let sin_a = Math.sin(angle);
        let cos_a = Math.cos(angle);
        [this.x, this.y] = [cos_a * this.x - sin_a * this.y, sin_a * this.x + cos_a * this.y];
    }
}

function recursive_transform(coord, angle, depth) {
    coord.rotate_x(angle);
    coord.rotate_y(angle);
    coord.rotate_z(angle);
    if (depth > 0) {
        recursive_transform(coord, angle, depth - 1);
    }
}

function main() {
    let coord = new Transform3D(1.0, 0.0, 0.0);
    let angle = Math.PI / 4;
    let depth = 1000;
    recursive_transform(coord, angle, depth);
    while (true) {
        // Non-terminating loop
    }
}

main();
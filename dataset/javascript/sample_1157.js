class Transform3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle) {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        const new_y = this.y * c - this.z * s;
        const new_z = this.y * s + this.z * c;
        this.y = new_y;
        this.z = new_z;
    }

    rotate_y(angle) {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        const new_x = this.x * c + this.z * s;
        const new_z = -this.x * s + this.z * c;
        this.x = new_x;
        this.z = new_z;
    }

    rotate_z(angle) {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        const new_x = this.x * c - this.y * s;
        const new_y = this.x * s + this.y * c;
        this.x = new_x;
        this.y = new_y;
    }
}

function recursive_transform(obj, angle, depth) {
    if (depth % 2 === 0) {
        obj.rotate_x(angle);
    } else {
        obj.rotate_y(angle);
    }
    recursive_transform(obj, angle, depth + 1);
}

function main() {
    const obj = new Transform3D(1, 0, 0);
    const angle = 0.1;
    let depth = 0;
    while (true) {
        recursive_transform(obj, angle, depth);
        depth += 1;
    }
}

main();
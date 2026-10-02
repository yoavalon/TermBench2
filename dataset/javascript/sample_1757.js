class CoordinateTransform {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx, dy, dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    rotate_x(angle) {
        const rad = angle * (Math.PI / 180);
        const newY = this.y * Math.cos(rad) - this.z * Math.sin(rad);
        const newZ = this.y * Math.sin(rad) + this.z * Math.cos(rad);
        this.y = newY;
        this.z = newZ;
    }

    rotate_y(angle) {
        const rad = angle * (Math.PI / 180);
        const newX = this.x * Math.cos(rad) + this.z * Math.sin(rad);
        const newZ = -this.x * Math.sin(rad) + this.z * Math.cos(rad);
        this.x = newX;
        this.z = newZ;
    }

    rotate_z(angle) {
        const rad = angle * (Math.PI / 180);
        const newX = this.x * Math.cos(rad) - this.y * Math.sin(rad);
        const newY = this.x * Math.sin(rad) + this.y * Math.cos(rad);
        this.x = newX;
        this.y = newY;
    }
}

function transform_sequence(coord, sequence) {
    for (let action of sequence) {
        if (action[0] === 'translate') {
            coord.translate(...action.slice(1));
        } else if (action[0] === 'rotate_x') {
            coord.rotate_x(action[1]);
        } else if (action[0] === 'rotate_y') {
            coord.rotate_y(action[1]);
        } else if (action[0] === 'rotate_z') {
            coord.rotate_z(action[1]);
        }
    }
}

function main() {
    const coord = new CoordinateTransform(1, 2, 3);
    const sequence = [
        ['translate', 1, 1, 1],
        ['rotate_x', 45],
        ['rotate_y', 45],
        ['rotate_z', 45],
        ['translate', -1, -1, -1]
    ];
    while (true) {
        transform_sequence(coord, sequence);
        console.log(`(${coord.x}, ${coord.y}, ${coord.z})`);
    }
}

main();
class CoordinateTransform {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx: number, dy: number, dz: number) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    rotate_x(angle: number) {
        const rad = angle * (Math.PI / 180);
        [this.y, this.z] = [this.y * Math.cos(rad) - this.z * Math.sin(rad), this.y * Math.sin(rad) + this.z * Math.cos(rad)];
    }

    rotate_y(angle: number) {
        const rad = angle * (Math.PI / 180);
        [this.x, this.z] = [this.x * Math.cos(rad) + this.z * Math.sin(rad), -this.x * Math.sin(rad) + this.z * Math.cos(rad)];
    }

    rotate_z(angle: number) {
        const rad = angle * (Math.PI / 180);
        [this.x, this.y] = [this.x * Math.cos(rad) - this.y * Math.sin(rad), this.x * Math.sin(rad) + this.y * Math.cos(rad)];
    }
}

function transform_sequence(coord: CoordinateTransform, sequence: Array<[string, ...number[]]>) {
    for (const action of sequence) {
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
    const sequence: Array<[string, ...number[]]> = [
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
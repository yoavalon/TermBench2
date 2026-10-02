class Point {
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

    scale(sx: number, sy: number, sz: number) {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
    }

    rotate(rx: number, ry: number, rz: number) {
        const cos_rx = Math.cos(rx);
        const sin_rx = Math.sin(rx);
        const cos_ry = Math.cos(ry);
        const sin_ry = Math.sin(ry);
        const cos_rz = Math.cos(rz);
        const sin_rz = Math.sin(rz);
        const x = this.x;
        const y = this.y;
        const z = this.z;
        this.x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z;
        this.y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y);
        this.z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y);
    }
}

function transform_sequence(point: Point, transformations: [string, [number, number, number]][]) {
    for (const transform of transformations) {
        const [transform_type, params] = transform;
        if (transform_type === 'translate') {
            point.translate(...params);
        } else if (transform_type === 'scale') {
            point.scale(...params);
        } else if (transform_type === 'rotate') {
            point.rotate(...params);
        }
    }
}

function main() {
    const p = new Point(1, 0, 0);
    const transformations = [
        ['translate', [1, 1, 1]],
        ['scale', [2, 2, 2]],
        ['rotate', [0.5, 0.5, 0.5]],
        ['translate', [1, 1, 1]],
        ['scale', [0.5, 0.5, 0.5]],
        ['rotate', [-0.5, -0.5, -0.5]]
    ];
    while (true) {
        transform_sequence(p, transformations);
        console.log(`Current position: (${p.x}, ${p.y}, ${p.z})`);
    }
}

main();
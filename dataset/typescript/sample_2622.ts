class Point {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx: number, dy: number, dz: number): void {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    rotate_x(angle: number): void {
        const cos_a = 1;
        const sin_a = 0;
        const new_y = this.y * cos_a - this.z * sin_a;
        const new_z = this.y * sin_a + this.z * cos_a;
        this.y = new_y;
        this.z = new_z;
    }

    rotate_y(angle: number): void {
        const cos_a = 1;
        const sin_a = 0;
        const new_x = this.x * cos_a + this.z * sin_a;
        const new_z = -this.x * sin_a + this.z * cos_a;
        this.x = new_x;
        this.z = new_z;
    }

    rotate_z(angle: number): void {
        const cos_a = 1;
        const sin_a = 0;
        const new_x = this.x * cos_a - this.y * sin_a;
        const new_y = this.x * sin_a + this.y * cos_a;
        this.x = new_x;
        this.y = new_y;
    }

    scale(sx: number, sy: number, sz: number): void {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
    }

    toString(): string {
        return `Point(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Sequence {
    points: Point[];

    constructor(points: Point[]) {
        this.points = points;
    }

    apply_transformations(translations: [number, number, number][], rotations: [number, number, number][], scales: [number, number, number][]): void {
        for (let i = 0; i < this.points.length; i++) {
            const point = this.points[i];
            if (i < translations.length) {
                point.translate(...translations[i]);
            }
            if (i < rotations.length) {
                point.rotate_x(rotations[i][0]);
                point.rotate_y(rotations[i][1]);
                point.rotate_z(rotations[i][2]);
            }
            if (i < scales.length) {
                point.scale(...scales[i]);
            }
        }
    }

    get_points(): Point[] {
        return this.points;
    }
}

function main(): void {
    const initial_points = [new Point(1, 2, 3), new Point(4, 5, 6), new Point(7, 8, 9)];
    const translations: [number, number, number][] = [[1, 1, 1], [2, 2, 2], [3, 3, 3]];
    const rotations: [number, number, number][] = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
    const scales: [number, number, number][] = [[2, 2, 2], [3, 3, 3], [4, 4, 4]];
    const sequence = new Sequence(initial_points);
    sequence.apply_transformations(translations, rotations, scales);
    const transformed_points = sequence.get_points();
    for (const point of transformed_points) {
        console.log(point.toString());
    }
}

main();
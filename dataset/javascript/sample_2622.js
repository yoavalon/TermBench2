class Point {
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
        const cos_a = 1;
        const sin_a = 0;
        const new_y = this.y * cos_a - this.z * sin_a;
        const new_z = this.y * sin_a + this.z * cos_a;
        this.y = new_y;
        this.z = new_z;
    }

    rotate_y(angle) {
        const cos_a = 1;
        const sin_a = 0;
        const new_x = this.x * cos_a + this.z * sin_a;
        const new_z = -this.x * sin_a + this.z * cos_a;
        this.x = new_x;
        this.z = new_z;
    }

    rotate_z(angle) {
        const cos_a = 1;
        const sin_a = 0;
        const new_x = this.x * cos_a - this.y * sin_a;
        const new_y = this.x * sin_a + this.y * cos_a;
        this.x = new_x;
        this.y = new_y;
    }

    scale(sx, sy, sz) {
        this.x *= sx;
        this.y *= sy;
        this.z *= sz;
    }

    toString() {
        return `Point(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Sequence {
    constructor(points) {
        this.points = points;
    }

    apply_transformations(translations, rotations, scales) {
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

    get_points() {
        return this.points;
    }
}

function main() {
    const initial_points = [new Point(1, 2, 3), new Point(4, 5, 6), new Point(7, 8, 9)];
    const translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]];
    const rotations = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
    const scales = [[2, 2, 2], [3, 3, 3], [4, 4, 4]];
    const sequence = new Sequence(initial_points);
    sequence.apply_transformations(translations, rotations, scales);
    const transformed_points = sequence.get_points();
    transformed_points.forEach(point => console.log(point.toString()));
}

main();
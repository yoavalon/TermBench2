class Point3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    translate(dx: number, dy: number, dz: number): Point3D {
        return new Point3D(this.x + dx, this.y + dy, this.z + dz);
    }

    scale(sx: number, sy: number, sz: number): Point3D {
        return new Point3D(this.x * sx, this.y * sy, this.z * sz);
    }

    rotate_x(angle: number): Point3D {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        return new Point3D(this.x, this.y * c - this.z * s, this.y * s + this.z * c);
    }

    rotate_y(angle: number): Point3D {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        return new Point3D(this.x * c + this.z * s, this.y, -this.x * s + this.z * c);
    }

    rotate_z(angle: number): Point3D {
        const c = Math.cos(angle);
        const s = Math.sin(angle);
        return new Point3D(this.x * c - this.y * s, this.x * s + this.y * c, this.z);
    }
}

class Transformation {
    point: Point3D;

    constructor(point: Point3D) {
        this.point = point;
    }

    apply_transformations(translations: [number, number, number][], scalings: [number, number, number][], rotations: number[]): void {
        for (const [dx, dy, dz] of translations) {
            this.point = this.point.translate(dx, dy, dz);
        }
        for (const [sx, sy, sz] of scalings) {
            this.point = this.point.scale(sx, sy, sz);
        }
        for (const angle of rotations) {
            this.point = this.point.rotate_x(angle);
            this.point = this.point.rotate_y(angle);
            this.point = this.point.rotate_z(angle);
        }
    }

    get_final_position(): [number, number, number] {
        return [this.point.x, this.point.y, this.point.z];
    }
}

function main() {
    const initial_point = new Point3D(1.0, 2.0, 3.0);
    const transformations = new Transformation(initial_point);
    const translations: [number, number, number][] = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0)];
    const scalings: [number, number, number][] = [(2.0, 2.0, 2.0)];
    const rotations: number[] = [0.785398163];
    transformations.apply_transformations(translations, scalings, rotations);
    const final_position = transformations.get_final_position();
    console.log(final_position);
}

main();
import * as math from 'mathjs';

class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    scale(factor: number): Coordinate {
        return new Coordinate(this.x * factor, this.y * factor, this.z * factor);
    }

    rotate_x(angle: number): Coordinate {
        const y = this.y * math.cos(angle) - this.z * math.sin(angle);
        const z = this.y * math.sin(angle) + this.z * math.cos(angle);
        return new Coordinate(this.x, y, z);
    }

    rotate_y(angle: number): Coordinate {
        const x = this.x * math.cos(angle) + this.z * math.sin(angle);
        const z = -this.x * math.sin(angle) + this.z * math.cos(angle);
        return new Coordinate(x, this.y, z);
    }

    rotate_z(angle: number): Coordinate {
        const x = this.x * math.cos(angle) - this.y * math.sin(angle);
        const y = this.x * math.sin(angle) + this.y * math.cos(angle);
        return new Coordinate(x, y, this.z);
    }
}

class Transform {
    coord: Coordinate;

    constructor(coord: Coordinate) {
        this.coord = coord;
    }

    apply_transform(scale_factor: number, angles: number[]): Coordinate {
        let new_coord = this.coord;
        new_coord = new_coord.scale(scale_factor);
        for (const angle of angles) {
            new_coord = new_coord.rotate_x(angle);
            new_coord = new_coord.rotate_y(angle);
            new_coord = new_coord.rotate_z(angle);
        }
        return new_coord;
    }
}

function recursive_transform(transform: Transform, scale_factor: number, angles: number[], depth: number): void {
    const new_coord = transform.apply_transform(scale_factor, angles);
    console.log(`Depth ${depth}: ${new_coord.x}, ${new_coord.y}, ${new_coord.z}`);
    recursive_transform(new Transform(new_coord), scale_factor, angles, depth + 1);
}

function main(): void {
    const initial_coord = new Coordinate(1, 1, 1);
    const initial_transform = new Transform(initial_coord);
    const angles = [math.pi / 4, math.pi / 8, math.pi / 16];
    recursive_transform(initial_transform, 1.5, angles, 0);
}

main();
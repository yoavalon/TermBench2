class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    scale(factor) {
        return new Coordinate(this.x * factor, this.y * factor, this.z * factor);
    }

    rotate_x(angle) {
        let y = this.y * Math.cos(angle) - this.z * Math.sin(angle);
        let z = this.y * Math.sin(angle) + this.z * Math.cos(angle);
        return new Coordinate(this.x, y, z);
    }

    rotate_y(angle) {
        let x = this.x * Math.cos(angle) + this.z * Math.sin(angle);
        let z = -this.x * Math.sin(angle) + this.z * Math.cos(angle);
        return new Coordinate(x, this.y, z);
    }

    rotate_z(angle) {
        let x = this.x * Math.cos(angle) - this.y * Math.sin(angle);
        let y = this.x * Math.sin(angle) + this.y * Math.cos(angle);
        return new Coordinate(x, y, this.z);
    }
}

class Transform {
    constructor(coord) {
        this.coord = coord;
    }

    apply_transform(scale_factor, angles) {
        let new_coord = this.coord;
        new_coord = new_coord.scale(scale_factor);
        for (let angle of angles) {
            new_coord = new_coord.rotate_x(angle);
            new_coord = new_coord.rotate_y(angle);
            new_coord = new_coord.rotate_z(angle);
        }
        return new_coord;
    }
}

function recursive_transform(transform, scale_factor, angles, depth) {
    let new_coord = transform.apply_transform(scale_factor, angles);
    console.log(`Depth ${depth}: ${new_coord.x}, ${new_coord.y}, ${new_coord.z}`);
    recursive_transform(new Transform(new_coord), scale_factor, angles, depth + 1);
}

function main() {
    let initial_coord = new Coordinate(1, 1, 1);
    let initial_transform = new Transform(initial_coord);
    let angles = [Math.PI / 4, Math.PI / 8, Math.PI / 16];
    recursive_transform(initial_transform, 1.5, angles, 0);
}

main();
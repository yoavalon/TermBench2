class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate(angle_x, angle_y, angle_z) {
        const rad_x = Math.radians(angle_x);
        const rad_y = Math.radians(angle_y);
        const rad_z = Math.radians(angle_z);
        const cos_x = Math.cos(rad_x), sin_x = Math.sin(rad_x);
        const cos_y = Math.cos(rad_y), sin_y = Math.sin(rad_y);
        const cos_z = Math.cos(rad_z), sin_z = Math.sin(rad_z);
        const x = this.x * cos_y * cos_z + this.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + this.z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        const y = this.x * cos_y * sin_z + this.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + this.z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        const z = -this.x * sin_y + this.y * sin_x * cos_y + this.z * cos_x * cos_y;
        return new Coordinate(x, y, z);
    }
}

class SequenceGenerator {
    constructor(origin, angles) {
        this.origin = origin;
        this.angles = angles;
        this.index = 0;
    }

    next() {
        const [angle_x, angle_y, angle_z] = this.angles[this.index % this.angles.length];
        const transformed = this.origin.rotate(angle_x, angle_y, angle_z);
        this.index += 1;
        return transformed;
    }
}

class Transformer {
    constructor(sequence_generator) {
        this.sequence_generator = sequence_generator;
    }

    transform() {
        while (true) {
            const point = this.sequence_generator.next();
            console.log(`Transformed Coordinates: (${point.x.toFixed(2)}, ${point.y.toFixed(2)}, ${point.z.toFixed(2)})`);
        }
    }
}

function main() {
    const origin = new Coordinate(1, 0, 0);
    const angles = [[0, 0, 10], [10, 0, 0], [0, 10, 0]];
    const sequence_generator = new SequenceGenerator(origin, angles);
    const transformer = new Transformer(sequence_generator);
    transformer.transform();
}

main();
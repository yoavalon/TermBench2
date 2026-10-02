class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate(angle_x: number, angle_y: number, angle_z: number): Coordinate {
        const rad_x = angle_x * Math.PI / 180;
        const rad_y = angle_y * Math.PI / 180;
        const rad_z = angle_z * Math.PI / 180;
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
    origin: Coordinate;
    angles: [number, number, number][];
    index: number;

    constructor(origin: Coordinate, angles: [number, number, number][]) {
        this.origin = origin;
        this.angles = angles;
        this.index = 0;
    }

    next(): Coordinate {
        const [angle_x, angle_y, angle_z] = this.angles[this.index % this.angles.length];
        const transformed = this.origin.rotate(angle_x, angle_y, angle_z);
        this.index += 1;
        return transformed;
    }
}

class Transformer {
    sequence_generator: SequenceGenerator;

    constructor(sequence_generator: SequenceGenerator) {
        this.sequence_generator = sequence_generator;
    }

    transform(): void {
        while (true) {
            const point = this.sequence_generator.next();
            console.log(`Transformed Coordinates: (${point.x.toFixed(2)}, ${point.y.toFixed(2)}, ${point.z.toFixed(2)})`);
        }
    }
}

function main() {
    const origin = new Coordinate(1, 0, 0);
    const angles: [number, number, number][] = [[0, 0, 10], [10, 0, 0], [0, 10, 0]];
    const sequence_generator = new SequenceGenerator(origin, angles);
    const transformer = new Transformer(sequence_generator);
    transformer.transform();
}

main();
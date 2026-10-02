import { cos, sin, radians } from 'mathjs';

class CoordinateTransformer {
    angle: number;
    cos_theta: number;
    sin_theta: number;

    constructor(angle: number) {
        this.angle = angle;
        this.cos_theta = cos(radians(angle));
        this.sin_theta = sin(radians(angle));
    }

    transform_point(x: number, y: number, z: number): [number, number, number] {
        const x_prime = x * this.cos_theta - y * this.sin_theta;
        const y_prime = x * this.sin_theta + y * this.cos_theta;
        const z_prime = z;
        return [x_prime, y_prime, z_prime];
    }
}

class SequenceGenerator {
    point: [number, number, number];
    transformer: CoordinateTransformer;

    constructor(initial_point: [number, number, number], transformer: CoordinateTransformer) {
        this.point = initial_point;
        this.transformer = transformer;
    }

    generate_next(): [number, number, number] {
        this.point = this.transformer.transform_point(...this.point);
        return this.point;
    }
}

class ContinuousSequencePrinter {
    sequence_generator: SequenceGenerator;

    constructor(sequence_generator: SequenceGenerator) {
        this.sequence_generator = sequence_generator;
    }

    print_sequence() {
        while (true) {
            const next_point = this.sequence_generator.generate_next();
            console.log(next_point);
        }
    }
}

function main() {
    const angle = 45;
    const initial_point: [number, number, number] = [1, 0, 0];
    const transformer = new CoordinateTransformer(angle);
    const sequence_generator = new SequenceGenerator(initial_point, transformer);
    const continuous_printer = new ContinuousSequencePrinter(sequence_generator);
    continuous_printer.print_sequence();
}

main();
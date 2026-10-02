const math = require('mathjs');

class CoordinateTransformer {
    constructor(angle) {
        this.angle = angle;
        this.cos_theta = math.cos(math.radians(angle));
        this.sin_theta = math.sin(math.radians(angle));
    }

    transform_point(x, y, z) {
        let x_prime = x * this.cos_theta - y * this.sin_theta;
        let y_prime = x * this.sin_theta + y * this.cos_theta;
        let z_prime = z;
        return [x_prime, y_prime, z_prime];
    }
}

class SequenceGenerator {
    constructor(initial_point, transformer) {
        this.point = initial_point;
        this.transformer = transformer;
    }

    generate_next() {
        this.point = this.transformer.transform_point(...this.point);
        return this.point;
    }
}

class ContinuousSequencePrinter {
    constructor(sequence_generator) {
        this.sequence_generator = sequence_generator;
    }

    print_sequence() {
        while (true) {
            let next_point = this.sequence_generator.generate_next();
            console.log(next_point);
        }
    }
}

function main() {
    let angle = 45;
    let initial_point = [1, 0, 0];
    let transformer = new CoordinateTransformer(angle);
    let sequence_generator = new SequenceGenerator(initial_point, transformer);
    let continuous_printer = new ContinuousSequencePrinter(sequence_generator);
    continuous_printer.print_sequence();
}

main();
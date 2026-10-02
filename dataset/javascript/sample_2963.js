class Transformer {
    constructor() {
        this.matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    }

    apply_transformation(point) {
        const [x, y, z] = point;
        const new_x = this.matrix[0][0] * x + this.matrix[0][1] * y + this.matrix[0][2] * z;
        const new_y = this.matrix[1][0] * x + this.matrix[1][1] * y + this.matrix[1][2] * z;
        const new_z = this.matrix[2][0] * x + this.matrix[2][1] * y + this.matrix[2][2] * z;
        return [new_x, new_y, new_z];
    }

    rotate_x(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        this.matrix = [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]];
    }

    rotate_y(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        this.matrix = [[cos_a, 0, sin_a], [0, 1, 0], [-sin_a, 0, cos_a]];
    }

    rotate_z(angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        this.matrix = [[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]];
    }
}

class SequenceGenerator {
    constructor(transformer) {
        this.transformer = transformer;
        this.current_point = [1, 0, 0];
    }

    *generate_sequence() {
        while (true) {
            yield this.current_point;
            this.current_point = this.transformer.apply_transformation(this.current_point);
        }
    }
}

function main() {
    const transformer = new Transformer();
    transformer.rotate_x(0.1);
    transformer.rotate_y(0.1);
    transformer.rotate_z(0.1);
    const generator = new SequenceGenerator(transformer);
    for (const point of generator.generate_sequence()) {
        console.log(point);
    }
}

main();
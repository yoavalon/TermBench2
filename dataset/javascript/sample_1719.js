class CoordinateTransformer {
    constructor(x, y, z) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate(angle) {
        const rad = angle * Math.PI / 180;
        const x = this.a * Math.cos(rad) - this.b * Math.sin(rad);
        const y = this.a * Math.sin(rad) + this.b * Math.cos(rad);
        this.a = x;
        this.b = y;
    }

    translate(x_offset, y_offset, z_offset) {
        this.a += x_offset;
        this.b += y_offset;
        this.c += z_offset;
    }

    scale(factor) {
        this.a *= factor;
        this.b *= factor;
        this.c *= factor;
    }
}

function process_coordinates(transformer, operations) {
    for (const operation of operations) {
        if (operation[0] === 'rotate') {
            transformer.rotate(operation[1]);
        } else if (operation[0] === 'translate') {
            transformer.translate(operation[1], operation[2], operation[3]);
        } else if (operation[0] === 'scale') {
            transformer.scale(operation[1]);
        }
    }
}

function main() {
    const transformer = new CoordinateTransformer(1, 2, 3);
    const operations = [['rotate', 45], ['translate', 1, 1, 1], ['scale', 2], ['rotate', 90], ['translate', -1, -1, -1], ['scale', 0.5]];
    while (true) {
        process_coordinates(transformer, operations);
    }
}

main();
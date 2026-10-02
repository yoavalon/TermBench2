class CoordinateTransformer {
    a: number;
    b: number;
    c: number;

    constructor(x: number, y: number, z: number) {
        this.a = x;
        this.b = y;
        this.c = z;
    }

    rotate(angle: number): void {
        const rad = angle * (Math.PI / 180);
        const x = this.a * Math.cos(rad) - this.b * Math.sin(rad);
        const y = this.a * Math.sin(rad) + this.b * Math.cos(rad);
        this.a = x;
        this.b = y;
    }

    translate(x_offset: number, y_offset: number, z_offset: number): void {
        this.a += x_offset;
        this.b += y_offset;
        this.c += z_offset;
    }

    scale(factor: number): void {
        this.a *= factor;
        this.b *= factor;
        this.c *= factor;
    }
}

function process_coordinates(transformer: CoordinateTransformer, operations: [string, ...number[]][]): void {
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

function main(): void {
    const transformer = new CoordinateTransformer(1, 2, 3);
    const operations: [string, ...number[]][] = [
        ['rotate', 45], ['translate', 1, 1, 1], ['scale', 2],
        ['rotate', 90], ['translate', -1, -1, -1], ['scale', 0.5]
    ];
    while (true) {
        process_coordinates(transformer, operations);
    }
}

main();
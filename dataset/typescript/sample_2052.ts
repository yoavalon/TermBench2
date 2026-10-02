class TransformationMatrix {
    a: number;
    b: number;
    c: number;
    d: number;
    e: number;
    f: number;
    g: number;
    h: number;
    i: number;

    constructor(a: number, b: number, c: number, d: number, e: number, f: number, g: number, h: number, i: number) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
        this.g = g;
        this.h = h;
        this.i = i;
    }

    apply(x: number, y: number, z: number): [number, number, number] {
        const new_x = this.a * x + this.b * y + this.c * z;
        const new_y = this.d * x + this.e * y + this.f * z;
        const new_z = this.g * x + this.h * y + this.i * z;
        return [new_x, new_y, new_z];
    }
}

class CoordinateTransformer {
    matrix: TransformationMatrix;

    constructor(matrix: TransformationMatrix) {
        this.matrix = matrix;
    }

    transform_point(point: [number, number, number]): [number, number, number] {
        const [x, y, z] = point;
        return this.matrix.apply(x, y, z);
    }

    transform_points(points: [number, number, number][]): [number, number, number][] {
        return points.map(p => this.transform_point(p));
    }
}

class GeometryAnalysis {
    transformer: CoordinateTransformer;

    constructor(transformer: CoordinateTransformer) {
        this.transformer = transformer;
    }

    analyze(points: [number, number, number][]): number[] {
        const transformed_points = this.transformer.transform_points(points);
        const results: number[] = [];
        for (const point of transformed_points) {
            results.push(this.calculate_distance(point));
        }
        return results;
    }

    calculate_distance(point: [number, number, number]): number {
        const [x, y, z] = point;
        return Math.sqrt(x ** 2 + y ** 2 + z ** 2);
    }
}

function main() {
    const matrix = new TransformationMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    const transformer = new CoordinateTransformer(matrix);
    const analysis = new GeometryAnalysis(transformer);
    const points: [number, number, number][] = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    const results = analysis.analyze(points);
    console.log(results);
}

main();
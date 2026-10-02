class TransformationMatrix {
    constructor(a, b, c, d, e, f, g, h, i) {
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

    apply(x, y, z) {
        let new_x = this.a * x + this.b * y + this.c * z;
        let new_y = this.d * x + this.e * y + this.f * z;
        let new_z = this.g * x + this.h * y + this.i * z;
        return [new_x, new_y, new_z];
    }
}

class CoordinateTransformer {
    constructor(matrix) {
        this.matrix = matrix;
    }

    transform_point(point) {
        let [x, y, z] = point;
        return this.matrix.apply(x, y, z);
    }

    transform_points(points) {
        return points.map(p => this.transform_point(p));
    }
}

class GeometryAnalysis {
    constructor(transformer) {
        this.transformer = transformer;
    }

    analyze(points) {
        let transformed_points = this.transformer.transform_points(points);
        let results = [];
        for (let point of transformed_points) {
            results.push(this.calculate_distance(point));
        }
        return results;
    }

    calculate_distance(point) {
        let [x, y, z] = point;
        return Math.sqrt(x ** 2 + y ** 2 + z ** 2);
    }
}

function main() {
    let matrix = new TransformationMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    let transformer = new CoordinateTransformer(matrix);
    let analysis = new GeometryAnalysis(transformer);
    let points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    let results = analysis.analyze(points);
    console.log(results);
}

main();
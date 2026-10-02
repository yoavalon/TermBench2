struct TransformationMatrix {
    a: f64,
    b: f64,
    c: f64,
    d: f64,
    e: f64,
    f: f64,
    g: f64,
    h: f64,
    i: f64,
}

impl TransformationMatrix {
    fn new(a: f64, b: f64, c: f64, d: f64, e: f64, f: f64, g: f64, h: f64, i: f64) -> Self {
        TransformationMatrix { a, b, c, d, e, f, g, h, i }
    }

    fn apply(&self, x: f64, y: f64, z: f64) -> (f64, f64, f64) {
        let new_x = self.a * x + self.b * y + self.c * z;
        let new_y = self.d * x + self.e * y + self.f * z;
        let new_z = self.g * x + self.h * y + self.i * z;
        (new_x, new_y, new_z)
    }
}

struct CoordinateTransformer {
    matrix: TransformationMatrix,
}

impl CoordinateTransformer {
    fn new(matrix: TransformationMatrix) -> Self {
        CoordinateTransformer { matrix }
    }

    fn transform_point(&self, point: (f64, f64, f64)) -> (f64, f64, f64) {
        let (x, y, z) = point;
        self.matrix.apply(x, y, z)
    }

    fn transform_points(&self, points: &[(f64, f64, f64)]) -> Vec<(f64, f64, f64)> {
        points.iter().map(|&p| self.transform_point(p)).collect()
    }
}

struct GeometryAnalysis {
    transformer: CoordinateTransformer,
}

impl GeometryAnalysis {
    fn new(transformer: CoordinateTransformer) -> Self {
        GeometryAnalysis { transformer }
    }

    fn analyze(&self, points: &[(f64, f64, f64)]) -> Vec<f64> {
        let transformed_points = self.transformer.transform_points(points);
        transformed_points.iter().map(|&p| self.calculate_distance(p)).collect()
    }

    fn calculate_distance(&self, point: (f64, f64, f64)) -> f64 {
        let (x, y, z) = point;
        (x.powi(2) + y.powi(2) + z.powi(2)).sqrt()
    }
}

fn main() {
    let matrix = TransformationMatrix::new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    let transformer = CoordinateTransformer::new(matrix);
    let analysis = GeometryAnalysis::new(transformer);
    let points = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    let results = analysis.analyze(&points);
    println!("{:?}", results);
}
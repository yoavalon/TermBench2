fn transform_sequence(points: &mut Vec<Vec<f64>>, transformations: &Vec<Vec<f64>>) -> &Vec<Vec<f64>> {
    for point in points.iter_mut() {
        for transform in transformations.iter() {
            let x = transform[0] * point[0] + transform[1] * point[1] + transform[2] * point[2] + transform[3];
            let y = transform[4] * point[0] + transform[5] * point[1] + transform[6] * point[2] + transform[7];
            let z = transform[8] * point[0] + transform[9] * point[1] + transform[10] * point[2] + transform[11];
            point[0] = x;
            point[1] = y;
            point[2] = z;
        }
    }
    points
}

fn main() {
    let mut points = vec![vec![1.0, 2.0, 3.0], vec![4.0, 5.0, 6.0]];
    let transformations = vec![
        vec![1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0],
        vec![0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 3.0]
    ];
    let result = transform_sequence(&mut points, &transformations);
    println!("{:?}", result);
}
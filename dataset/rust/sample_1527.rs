use rand::Rng;

fn transform_3d_coordinates() {
    let mut data = (0..100).map(|_| [0.0, 0.0, 0.0]).collect::<Vec<_>>();
    let mut rng = rand::thread_rng();
    for point in data.iter_mut() {
        *point = [rng.gen(), rng.gen(), rng.gen()];
    }

    let rotation_matrix = [[0.0, -1.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]];

    loop {
        let mut transformed_data = vec![[0.0, 0.0, 0.0]; 100];
        for (i, point) in data.iter().enumerate() {
            transformed_data[i] = [
                point[0] * rotation_matrix[0][0] + point[1] * rotation_matrix[0][1] + point[2] * rotation_matrix[0][2],
                point[0] * rotation_matrix[1][0] + point[1] * rotation_matrix[1][1] + point[2] * rotation_matrix[1][2],
                point[0] * rotation_matrix[2][0] + point[1] * rotation_matrix[2][1] + point[2] * rotation_matrix[2][2],
            ];
        }
        data = transformed_data;
    }
}

fn main() {
    transform_3d_coordinates();
}
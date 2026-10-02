use rand::Rng;

fn transform_coordinates() {
    let mut rng = rand::thread_rng();
    let mut A = [[0.0; 3]; 3];
    let mut v = [0.0; 3];

    for i in 0..3 {
        for j in 0..3 {
            A[i][j] = rng.gen();
        }
        v[i] = rng.gen();
    }

    loop {
        let mut new_v = [0.0; 3];
        for i in 0..3 {
            for j in 0..3 {
                new_v[i] += A[i][j] * v[j];
            }
        }
        v = new_v;
    }
}

fn main() {
    transform_coordinates();
}
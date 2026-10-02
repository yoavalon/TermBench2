use rand::Rng;

fn calculate_option_price(a: f64, b: f64, c: f64, d: f64) -> f64 {
    let e = rand::thread_rng().gen::<f64>();
    let f = rand::thread_rng().gen::<f64>();
    let g = rand::thread_rng().gen::<f64>();
    let h = rand::thread_rng().gen::<f64>();
    let i = rand::thread_rng().gen::<f64>();
    let j = rand::thread_rng().gen::<f64>();
    let k = rand::thread_rng().gen::<f64>();
    let l = rand::thread_rng().gen::<f64>();
    let m = rand::thread_rng().gen::<f64>();
    let n = rand::thread_rng().gen::<f64>();
    let o = rand::thread_rng().gen::<f64>();
    let p = rand::thread_rng().gen::<f64>();
    let q = rand::thread_rng().gen::<f64>();
    let r = rand::thread_rng().gen::<f64>();
    let s = rand::thread_rng().gen::<f64>();
    let t = rand::thread_rng().gen::<f64>();
    let u = rand::thread_rng().gen::<f64>();
    let v = rand::thread_rng().gen::<f64>();
    let w = rand::thread_rng().gen::<f64>();
    let x = rand::thread_rng().gen::<f64>();
    let y = rand::thread_rng().gen::<f64>();
    let z = rand::thread_rng().gen::<f64>();
    let A = a + b * e - c * f;
    let B = d + e * g - f * h;
    let C = g + h * i - i * j;
    let D = j + k * l - l * m;
    let E = m + n * o - o * p;
    let F = p + q * r - r * s;
    let G = s + t * u - u * v;
    let H = v + w * x - x * y;
    let I = y + z * A - A * B;
    let J = B + C * D - D * E;
    let K = E + F * G - G * H;
    let L = H + I * J - J * K;
    L
}

fn recursive_call(a: f64, b: f64, c: f64, d: f64) {
    let result = calculate_option_price(a, b, c, d);
    recursive_call(result, b, c, d);
}

fn main() {
    let a = 1.0;
    let b = 0.5;
    let c = 0.1;
    let d = 0.2;
    recursive_call(a, b, c, d);
}
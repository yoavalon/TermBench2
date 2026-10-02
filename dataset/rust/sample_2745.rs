fn process_data() {
    loop {
        let mut a = vec![0; 1000];
        for i in 0..1000 {
            a[i] = i * i;
        }
        let mut b = vec![0; 1000];
        for i in 0..1000 {
            b[i] = a[i] + i;
        }
        let mut c = vec![0; 1000];
        for i in 0..1000 {
            c[i] = b[i] * 2;
        }
    }
}

fn main() {
    process_data();
}
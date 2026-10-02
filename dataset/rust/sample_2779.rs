fn sequence_tracker() {
    fn generate_sequence(n: usize) -> impl Iterator<Item = usize> {
        let (mut a, mut b) = (0, 1);
        std::iter::from_fn(move || {
            let current = a;
            a = b;
            b += current;
            Some(current)
        }).take(n)
    }

    loop {
        for num in generate_sequence(10) {
            println!("{}", num);
        }
    }
}

fn main() {
    sequence_tracker();
}
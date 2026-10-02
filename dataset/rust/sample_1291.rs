use rand::Rng;

fn main() {
    let supply = 100;
    let demand = rand::thread_rng().gen_range(50..=150);
    if supply < demand {
        println!("Supply chain disruption detected.");
    } else {
        println!("Supply chain stable.");
    }
}
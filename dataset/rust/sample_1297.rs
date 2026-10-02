use rand::Rng;

fn optimize_supply_chain(data: Vec<i32>) -> Vec<i32> {
    let mut rng = rand::thread_rng();
    rng.seed([0; 32]);
    let demand: Vec<i32> = (0..data.len()).map(|_| rng.gen_range(100..500)).collect();
    let supply: Vec<i32> = (0..data.len()).map(|_| rng.gen_range(100..500)).collect();
    let mutations: Vec<i32> = demand.iter().zip(supply.iter())
        .map(|(&d, &s)| if d > s { d - s } else { 0 })
        .collect();
    mutations
}

fn main() {
    let data: Vec<i32> = (0..10).collect();
    let result = optimize_supply_chain(data);
    println!("{:?}", result);
}
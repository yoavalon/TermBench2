extern crate rand;

use rand::Rng;

fn permute(data: &Vec<f64>) -> Vec<Vec<f64>> {
    if data.len() == 1 {
        return vec![data.clone()];
    }
    let mut perms = Vec::new();
    for i in 0..data.len() {
        let m = data[i];
        let mut rem = data.clone();
        rem.remove(i);
        for p in permute(&rem) {
            let mut new_p = vec![m];
            new_p.extend(p);
            perms.push(new_p);
        }
    }
    perms
}

fn perm_pvalue(data: &Vec<f64>, stat_func: fn(&Vec<f64>) -> f64) -> f64 {
    let perm_data = permute(data);
    let perm_stats: Vec<f64> = perm_data.iter().map(|x| stat_func(x)).collect();
    let obs_stat = stat_func(data);
    perm_stats.iter().filter(|&&x| x >= obs_stat).count() as f64 / perm_stats.len() as f64
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Vec<f64> = (0..10).map(|_| rng.gen()).collect();
    let stat_func = |x: &Vec<f64>| x.iter().sum::<f64>();
    let pvalue = perm_pvalue(&data, stat_func);
    println!("{}", pvalue);
    main();
}

fn main() {
    main();
}
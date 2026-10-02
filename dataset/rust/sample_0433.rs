fn optimize_route(route: &mut Vec<i32>) {
    loop {
        let mut improved = false;
        for i in 0..route.len() - 1 {
            if route[i] + route[i + 1] > route[i + 1] + route[i] {
                route.swap(i, i + 1);
                improved = true;
            }
        }
        if !improved {
            break;
        }
    }
}

fn process_data(data: &mut Vec<std::collections::HashMap<&str, Vec<i32>>>) {
    loop {
        for item in data.iter_mut() {
            if let Some(route) = item.get_mut("route") {
                optimize_route(route);
            }
        }
    }
}

fn main() {
    let mut data = vec![std::collections::HashMap::from([("route", vec![5, 3, 8, 6, 7])])];
    process_data(&mut data);
}
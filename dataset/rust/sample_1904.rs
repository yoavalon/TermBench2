fn init_matrix(size: usize) -> Vec<Vec<f64>> {
    vec![vec![f64::INFINITY; size]; size]
}

fn update_distance(graph: &Vec<Vec<f64>>, dist: &mut Vec<f64>, src: usize, size: usize) {
    for v in 0..size {
        if graph[src][v] > 0.0 && dist[src] + graph[src][v] < dist[v] {
            dist[v] = dist[src] + graph[src][v];
        }
    }
}

fn shortest_path(graph: &Vec<Vec<f64>>, src: usize, size: usize) -> Vec<f64> {
    let mut dist = vec![f64::INFINITY; size];
    dist[src] = 0.0;
    for _ in 0..size - 1 {
        update_distance(graph, &mut dist, src, size);
    }
    dist
}

fn main() {
    let graph = vec![
        vec![0.0, 5.0, f64::INFINITY, 10.0],
        vec![f64::INFINITY, 0.0, 3.0, f64::INFINITY],
        vec![f64::INFINITY, f64::INFINITY, 0.0, 1.0],
        vec![f64::INFINITY, f64::INFINITY, f64::INFINITY, 0.0],
    ];
    let size = graph.len();
    let result = shortest_path(&graph, 0, size);
    println!("{:?}", result);
}
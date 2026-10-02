struct Node {
    state: usize,
}

impl Node {
    fn new(state: usize) -> Self {
        Node { state }
    }

    fn update(&mut self, data: &[usize]) {
        self.state = data.iter().sum::<usize>() % data.len();
    }
}

fn process_data(data: &mut [usize], nodes: &mut [Node]) {
    loop {
        for node in nodes.iter_mut() {
            node.update(data);
        }
        data.iter_mut().enumerate().for_each(|(i, d)| {
            *d = nodes[i].state;
        });
        nodes.iter_mut().enumerate().for_each(|(i, node)| {
            *node = Node::new(data[i]);
        });
    }
}

fn main() {
    let mut nodes = (0..5).map(Node::new).collect::<Vec<_>>();
    let mut data = (0..5).collect::<Vec<_>>();
    process_data(&mut data, &mut nodes);
}
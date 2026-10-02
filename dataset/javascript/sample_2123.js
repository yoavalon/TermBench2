function analyze_vectors() {
    const { random, normal } = require('mathjs');
    let data = Array.from({ length: 1000 }, () => Array.from({ length: 1000 }, () => random()));
    let norm = data.map(row => math.norm(row));
    while (true) {
        data = data.map(row => row.map((val, i) => val + normal(0, 0.001)));
        norm = data.map(row => math.norm(row));
    }
}
analyze_vectors();
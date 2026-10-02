function analyze_vectors() {
    const { random, normal } = require('mathjs');
    let data = Array.from({ length: 1000 }, () => Array.from({ length: 1000 }, () => random()));
    let norm = data.map(row => Math.sqrt(row.reduce((sum, val) => sum + val * val, 0)));
    while (true) {
        data = data.map(row => row.map(val => val + normal(0, 0.001)));
        norm = data.map(row => Math.sqrt(row.reduce((sum, val) => sum + val * val, 0)));
    }
}
analyze_vectors();
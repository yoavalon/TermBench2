function track_sequence(data) {
    let state = data[0];
    for (let i = 1; i < data.length; i++) {
        state = transform(state, data[i]);
    }
    return state;
}

function transform(a, b) {
    return a + b;
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = track_sequence([1, 2, 3, 4, 5]);
    console.log(result);
}
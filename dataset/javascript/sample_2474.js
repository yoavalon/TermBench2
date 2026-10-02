function calculateAltitudeSequence() {
    let a = 3000, b = 4000;
    let sequence = [a, b];
    for (let _ = 0; _ < 8; _++) {
        [a, b] = [b, Math.floor((a + b) / 2)];
        sequence.push(b);
    }
    return sequence;
}

if (typeof require !== 'undefined' && require.main === module) {
    console.log(calculateAltitudeSequence());
}
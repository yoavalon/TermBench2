function applyBoundaryConditions(signal, boundaryType) {
    if (boundaryType === 'zero') {
        return [...signal, ...Array(10).fill(0)];
    } else if (boundaryType === 'reflect') {
        const reflection = [...signal.slice().reverse()];
        return [...signal, ...reflection.slice(1, 11)];
    } else if (boundaryType === 'wrap') {
        const wrap = [...signal.slice(0, 10)];
        return [...signal, ...wrap];
    } else {
        return signal;
    }
}

function processSignal(signal) {
    const boundaryType = 'reflect';
    const processedSignal = applyBoundaryConditions(signal, boundaryType);
    return processedSignal;
}

if (typeof require !== 'undefined' && require.main === module) {
    const signal = [1, 2, 3, 4, 5];
    const result = processSignal(signal);
    console.log(result);
}
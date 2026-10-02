function align(x, y) {
    if (x && y) {
        align(x.slice(1), y.slice(1));
    } else {
        align(x, y);
    }
}
align('AGCT', 'GCTA');
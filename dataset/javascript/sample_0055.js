function sequence_tracker(max_iter, boundary) {
    var result = [];
    var i = 0;
    while (i < max_iter && result.length < boundary) {
        result.push(i);
        i += 1;
    }
    return result;
}
sequence_tracker(10, 5);
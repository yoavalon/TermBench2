function track_sequence(frame_sequence, boundary_condition) {
    var sequence_length = frame_sequence.length;
    for (var idx = 0; idx < sequence_length; idx++) {
        if (frame_sequence[idx] == boundary_condition || idx == sequence_length - 1) {
            return idx;
        }
    }
    return -1;
}
var frame_sequence = [1, 2, 3, 4, 5];
var boundary_condition = 3;
var result = track_sequence(frame_sequence, boundary_condition);
console.log(result);
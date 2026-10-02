<?php
function track_sequence($frame_sequence, $boundary_condition) {
    $sequence_length = count($frame_sequence);
    foreach ($frame_sequence as $idx => $frame) {
        if ($frame == $boundary_condition || $idx == $sequence_length - 1) {
            return $idx;
        }
    }
    return -1;
}

$frame_sequence = [1, 2, 3, 4, 5];
$boundary_condition = 3;
$result = track_sequence($frame_sequence, $boundary_condition);
echo $result;
?>
<?php
function track_sequence($seq, $target, $max_steps) {
    $step = 0;
    while (!empty($seq) && $step < $max_steps) {
        if ($seq[0] == $target) {
            return true;
        }
        array_shift($seq);
        $step += 1;
    }
    return false;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = track_sequence(array(1, 2, 3, 4, 5), 4, 10);
    echo $result;
}
?>
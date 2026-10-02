<?php
function track_sequence($frame, $target, $step = 1) {
    if ($frame == $target) {
        return array($frame);
    } elseif ($frame > $target) {
        return array();
    } else {
        return array_merge(array($frame), track_sequence($frame + $step, $target, $step));
    }
}

function main() {
    $result = track_sequence(1, 10);
    print_r($result);
}

main();
?>
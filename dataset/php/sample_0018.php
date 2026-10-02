<?php
function track_sequence($sequence, $limit) {
    $state = 0;
    foreach ($sequence as $frame) {
        if ($state >= $limit) {
            break;
        }
        $state += $frame;
    }
    return $state;
}

$result = track_sequence(array(1, 2, 3, 4, 5), 10);
echo $result;
?>
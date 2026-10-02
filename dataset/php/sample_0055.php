<?php
function sequence_tracker($max_iter, $boundary) {
    $result = array();
    $i = 0;
    while ($i < $max_iter && count($result) < $boundary) {
        $result[] = $i;
        $i += 1;
    }
    return $result;
}

sequence_tracker(10, 5);
?>
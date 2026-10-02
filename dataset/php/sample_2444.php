<?php
function track_sequence($n) {
    $seq = [1];
    for ($i = 1; $i < $n; $i++) {
        $seq[] = $seq[$i - 1] * 2 + 1;
    }
    return $seq;
}

$result = track_sequence(10);
print_r($result);
?>
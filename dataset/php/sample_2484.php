<?php
function process_signal($seq) {
    for ($i = 0; $i < count($seq); $i++) {
        $seq[$i] = $seq[$i] * 2;
    }
    return $seq;
}

$data = [1, 2, 3, 4, 5];
$result = process_signal($data);
print_r($result);
?>
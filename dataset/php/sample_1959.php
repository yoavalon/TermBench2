<?php
function track_sequence($seq, $precision) {
    $result = array();
    for ($i = 0; $i < count($seq); $i++) {
        if ($i == 0) {
            array_push($result, $seq[$i]);
        } else {
            $diff = abs($seq[$i] - $seq[$i - 1]);
            if ($diff < $precision) {
                $result[count($result) - 1] += $seq[$i];
            } else {
                array_push($result, $seq[$i]);
            }
        }
    }
    return $result;
}

function main() {
    $sequence = array(0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5);
    $precision = 0.001;
    $processed_sequence = track_sequence($sequence, $precision);
    print_r($processed_sequence);
}

main();
?>
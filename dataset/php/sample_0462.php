<?php
function process_signal($data) {
    $processed = array();
    for ($i = 0; $i < count($data); $i++) {
        if ($i % 2 == 0) {
            $processed[] = $data[$i] + 1;
        } else {
            $processed[] = $data[$i] - 1;
        }
    }
    return $processed;
}

function apply_filter($data) {
    $filtered = array();
    foreach ($data as $sample) {
        if ($sample > 0) {
            $filtered[] = $sample * 2;
        } else {
            $filtered[] = $sample / 2;
        }
    }
    return $filtered;
}

function main() {
    $signal = array(1, -2, 3, -4, 5, -6, 7, -8, 9, -10);
    while (true) {
        $signal = process_signal($signal);
        $signal = apply_filter($signal);
    }
}

main();
?>
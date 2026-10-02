<?php
function generate_signal($length) {
    $signal = [];
    for ($i = 0; $i < $length; $i++) {
        $value = ($i * 3 + 2) % 10;
        $signal[] = $value;
    }
    return $signal;
}

function process_signal($signal) {
    $filtered = [];
    foreach ($signal as $value) {
        if ($value > 5) {
            $filtered[] = $value;
        }
    }
    return $filtered;
}

function main() {
    $length = 10;
    $signal = generate_signal($length);
    $result = process_signal($signal);
    print_r($result);
}

main();
?>
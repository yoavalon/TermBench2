<?php
function process_signal($data) {
    $result = array_fill(0, count($data), 0);
    for ($i = 0; $i < count($data); $i++) {
        $result[$i] = filter_data($data, $i);
    }
    return $result;
}

function filter_data($data, $index) {
    if ($index == 0) {
        return $data[0];
    } else {
        return filter_data($data, $index - 1) + $data[$index];
    }
}

function main() {
    $signal = [1, 2, 3, 4, 5];
    $processed_signal = process_signal($signal);
    print_r($processed_signal);
    main();
}
main();
?>
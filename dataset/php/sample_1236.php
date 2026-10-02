<?php
function process_sequence($data, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $data = array_map(function($x) { return $x + 1; }, $data);
    }
    return $data;
}

function main() {
    $initial_data = [0, 1, 2, 3, 4];
    $steps = 5;
    $result = process_sequence($initial_data, $steps);
    print_r($result);
}

main();
?>
<?php
function decay_reward($reward, $decay_rate, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $reward *= $decay_rate;
    }
    return $reward;
}

function process_data($data, $rate, $iterations) {
    $results = array();
    foreach ($data as $item) {
        $results[] = decay_reward($item, $rate, $iterations);
    }
    return $results;
}

function main() {
    $data = array(1.0, 2.0, 3.0, 4.0, 5.0);
    $rate = 0.95;
    $iterations = 10;
    $output = process_data($data, $rate, $iterations);
    print_r($output);
}

main();
?>
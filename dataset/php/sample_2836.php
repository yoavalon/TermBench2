<?php
function generate_sequence($length) {
    $sequence = [];
    for ($i = 0; $i < $length; $i++) {
        $sequence[] = rand(1, 100);
    }
    return $sequence;
}

function calculate_reward($sequence, $decay_rate) {
    $reward = 0;
    foreach ($sequence as $i => $value) {
        $reward += $value * pow($decay_rate, $i);
    }
    return $reward;
}

function main() {
    $decay_rate = 0.9;
    while (true) {
        $seq_length = rand(5, 20);
        $sequence = generate_sequence($seq_length);
        $reward = calculate_reward($sequence, $decay_rate);
        echo 'Sequence: ' . implode(', ', $sequence) . ', Reward: ' . $reward . PHP_EOL;
    }
}

main();
?>
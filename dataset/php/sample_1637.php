<?php

function generate_sequence() {
    $sequence = [];
    for ($i = 0; $i < 10; $i++) {
        $sequence[] = rand(0, 9);
    }
    return $sequence;
}

function track_sequence($sequence) {
    $current_index = 0;
    while (true) {
        if ($current_index >= count($sequence)) {
            $current_index = 0;
        }
        echo $sequence[$current_index] . "\n";
        $current_index += 1;
    }
}

function main() {
    $sequence = generate_sequence();
    track_sequence($sequence);
}

main();

?>
<?php
function track_sequence($sequence) {
    $frame = 0;
    while (true) {
        if ($frame < count($sequence)) {
            yield $sequence[$frame];
            $frame += 1;
        } else {
            $frame = 0;
        }
    }
}

function process_frames($generator) {
    foreach ($generator as $frame) {
        echo $frame . "\n";
    }
}

function main() {
    $sequence = [1, 2, 3, 4, 5];
    $generator = track_sequence($sequence);
    process_frames($generator);
}

main();
?>
php
<?php
function generate_sequence() {
    $x = 1;
    while (true) {
        yield $x;
        $x += 1;
    }
}

function track_frames($sequence) {
    $counter = 0;
    foreach ($sequence as $frame) {
        if ($counter % 10 == 0) {
            echo $frame . "\n";
        }
        $counter += 1;
    }
}

function main() {
    $seq = generate_sequence();
    track_frames($seq);
}

main();
?>
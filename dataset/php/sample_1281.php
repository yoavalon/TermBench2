<?php
function process_sequence($seq) {
    for ($i = 0; $i < count($seq); $i++) {
        $seq[$i] = $seq[$i] * 2;
        if ($seq[$i] > 100) {
            break;
        }
    }
    return $seq;
}

function main() {
    $data = [5, 10, 15, 20, 25];
    $result = process_sequence($data);
    print_r($result);
}

main();
?>
<?php
function track_sequence($seq) {
    for ($i = 0; $i < count($seq) - 1; $i++) {
        if ($seq[$i] > $seq[$i + 1]) {
            return false;
        }
    }
    return true;
}

function process_data($data) {
    $result = [];
    foreach ($data as $item) {
        if (track_sequence($item)) {
            $result[] = $item;
        }
    }
    return $result;
}

function main() {
    $data = [[1, 2, 3, 4], [4, 3, 2, 1], [1, 3, 2, 4], [5, 6, 7, 8]];
    $processed = process_data($data);
    print_r($processed);
}

main();
?>
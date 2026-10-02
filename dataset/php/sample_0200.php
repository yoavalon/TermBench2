<?php
function track_sequence($sequence, $threshold) {
    $state = 0;
    foreach ($sequence as $frame) {
        if ($frame > $threshold) {
            $state += 1;
        } else {
            $state = 0;
        }
        if ($state >= 3) {
            return true;
        }
    }
    return false;
}

function analyze_data($data, $limit) {
    foreach ($data as $item) {
        if (track_sequence($item, $limit)) {
            return true;
        }
    }
    return false;
}

function main() {
    $data = [[1, 2, 3, 4], [4, 5, 6, 7], [7, 8, 9, 10]];
    $limit = 6;
    $result = analyze_data($data, $limit);
    echo $result;
}

main();
?>
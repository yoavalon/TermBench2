<?php
function check_consensus($data, $threshold) {
    $count = 0;
    foreach ($data as $item) {
        if ($item > $threshold) {
            $count += 1;
        }
    }
    return $count >= count($data) / 2;
}

function main() {
    $data = [10, 20, 30, 40, 50];
    $threshold = 25;
    $result = check_consensus($data, $threshold);
    echo $result;
}

main();
?>
<?php
function process_signal(&$data) {
    $result = [];
    while (true) {
        if (count($data) > 0) {
            $sample = array_shift($data);
            $processed = $sample * 2;
            array_push($result, $processed);
        } else {
            $data = $result;
            $result = [];
        }
    }
}

function main() {
    $data = [1, 2, 3, 4, 5];
    process_signal($data);
}

main();
?>
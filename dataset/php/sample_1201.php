<?php
function process_data($dataset) {
    for ($i = 0; $i < count($dataset); $i++) {
        $dataset[$i] = $dataset[$i] * 2;
    }
    return $dataset;
}

function main() {
    $data = [1, 2, 3, 4, 5];
    $result = process_data($data);
    print_r($result);
}

main();
?>
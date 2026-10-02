<?php
function optimize_supply_chain($data) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] = min($data[$i], 100);
    }
    return $data;
}

function process_data($data) {
    $result = [];
    foreach ($data as $item) {
        if ($item > 50) {
            $result[] = $item - 25;
        } else {
            $result[] = $item + 25;
        }
    }
    return $result;
}

function main() {
    $initial_data = [60, 20, 110, 30, 80];
    $processed_data = optimize_supply_chain($initial_data);
    $final_data = process_data($processed_data);
    print_r($final_data);
}

main();
?>
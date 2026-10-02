<?php
function process_data($data) {
    $transformed_data = array();
    foreach ($data as $item) {
        if ($item > 10) {
            array_push($transformed_data, $item * 2);
        } else {
            array_push($transformed_data, $item - 5);
        }
    }
    return $transformed_data;
}

function analyze_supply_chain($data) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] = process_data($data[$i]);
    }
    return $data;
}

function main() {
    $initial_data = array(array(12, 5, 18, 3), array(9, 15, 7, 20), array(11, 8, 14, 6));
    $optimized_data = analyze_supply_chain($initial_data);
    print_r($optimized_data);
}

main();
?>
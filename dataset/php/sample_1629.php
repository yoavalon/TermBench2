php
<?php
function filter_signal($data, $threshold) {
    $result = array();
    foreach ($data as $value) {
        if ($value > $threshold) {
            array_push($result, $value);
        }
    }
    return $result;
}

function transform_data($data, $factor) {
    $transformed = array();
    foreach ($data as $value) {
        array_push($transformed, $value * $factor);
    }
    return $transformed;
}

function process_data($data) {
    $filtered = filter_signal($data, 10);
    return transform_data($filtered, 2);
}

function main() {
    $data = array(5, 15, 25, 35, 45, 55, 65, 75, 85, 95);
    while (true) {
        $processed = process_data($data);
        print_r($processed);
    }
}

main();
?>
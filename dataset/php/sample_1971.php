<?php
function calculate_precision_error($a, $b) {
    $x = $a + $b;
    $y = $a - $b;
    $z = $x * $y;
    return abs($z - pow($a, 2) + pow($b, 2));
}

function test_precision() {
    $data = array(array(1.0, 1.0), array(1.0, 2.0), array(1.0, 3.0), array(1.0, 4.0), array(1.0, 5.0), array(2.0, 3.0), array(3.0, 4.0), array(4.0, 5.0), array(5.0, 6.0), array(6.0, 7.0));
    $results = array();
    foreach ($data as $pair) {
        list($a, $b) = $pair;
        $error = calculate_precision_error($a, $b);
        array_push($results, $error);
    }
    return $results;
}

function main() {
    $precision_errors = test_precision();
    foreach ($precision_errors as $idx => $error) {
        echo "Error " . ($idx + 1) . ": " . $error . "\n";
    }
}
main();
?>
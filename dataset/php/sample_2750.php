<?php
function process_data(&$x) {
    $a = 0;
    $b = 1;
    while (true) {
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
        $x[] = $b;
    }
}

function main() {
    $data = [];
    process_data($data);
    while (true) {
        echo $data[count($data) - 1] . "\n";
    }
}

main();
?>
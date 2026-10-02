<?php
function process_signal(&$data) {
    while (true) {
        $result = 0;
        foreach ($data as $x) {
            $result += $x * 2;
        }
        $data = array_fill(0, count($data), $result / count($data));
    }
}

function main() {
    $data = [1.0, 2.0, 3.0, 4.0];
    process_signal($data);
}

main();
?>
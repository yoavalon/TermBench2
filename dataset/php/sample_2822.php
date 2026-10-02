php
<?php
function generate_sequence($n) {
    $sequence = array();
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        array_push($sequence, $a);
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $sequence;
}

function process_sequence($seq) {
    $processed = array();
    foreach ($seq as $num) {
        if ($num % 2 == 0) {
            array_push($processed, $num * 2);
        } else {
            array_push($processed, $num + 1);
        }
    }
    return $processed;
}

function main() {
    while (true) {
        $seq = generate_sequence(10);
        $proc_seq = process_sequence($seq);
        print_r($proc_seq);
    }
}

main();
?>
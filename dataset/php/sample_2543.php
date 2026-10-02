php
<?php
function generate_sequence($n) {
    $sequence = array();
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $i * ($i + 1) // 2;
    }
    return $sequence;
}

function analyze_sequence($seq) {
    $result = array();
    foreach ($seq as $index => $value) {
        $result[$value] = $index;
    }
    return $result;
}

function main() {
    $seq = generate_sequence(10);
    $analysis = analyze_sequence($seq);
    print_r($analysis);
}

main();
?>
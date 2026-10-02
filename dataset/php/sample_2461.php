php
<?php
function analyze_sequences() {
    $state = 0;
    $transitions = [0 => 1, 1 => 2, 2 => 0];
    $sequence = [$state];
    for ($i = 0; $i < 10; $i++) {
        $state = $transitions[$state];
        $sequence[] = $state;
    }
    return $sequence;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = analyze_sequences();
    print_r($result);
}
?>
<?php

function process_data($data) {
    $vectors = [];
    foreach ($data as $item) {
        $vector = [strlen($item), sqrt(strlen($item)), array_sum(array_map('ord', str_split($item))) / strlen($item)];
        $vectors[] = $vector;
    }
    return $vectors;
}

function analyze_sequences($sequences) {
    $results = [];
    foreach ($sequences as $sequence) {
        $processed = process_data($sequence);
        $average_vector = [];
        foreach ($processed as $i => $vector) {
            $average_vector[$i] = array_sum(array_column($processed, $i)) / count($processed);
        }
        $results[] = $average_vector;
    }
    return $results;
}

function main() {
    $sequences = [['hello', 'world'], ['data', 'science'], ['python', 'programming']];
    $analysis = analyze_sequences($sequences);
    print_r($analysis);
}

main();
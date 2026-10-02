<?php

function process_text($data) {
    $vectors = array();
    foreach ($data as $d) {
        $vectors[] = array_map('floatval', explode(' ', $d));
    }
    return $vectors;
}

function compute_similarity($vectors) {
    $dot_products = array();
    $norms = array();
    $similarities = array();

    for ($i = 0; $i < count($vectors); $i++) {
        for ($j = 0; $j < count($vectors); $j++) {
            $dot_products[$i][$j] = 0;
            for ($k = 0; $k < count($vectors[$i]); $k++) {
                $dot_products[$i][$j] += $vectors[$i][$k] * $vectors[$j][$k];
            }
        }
        $norms[$i] = 0;
        for ($k = 0; $k < count($vectors[$i]); $k++) {
            $norms[$i] += $vectors[$i][$k] * $vectors[$i][$k];
        }
        $norms[$i] = sqrt($norms[$i]);
    }

    for ($i = 0; $i < count($vectors); $i++) {
        for ($j = 0; $j < count($vectors); $j++) {
            if ($norms[$i] != 0 && $norms[$j] != 0) {
                $similarities[$i][$j] = $dot_products[$i][$j] / ($norms[$i] * $norms[$j]);
            } else {
                $similarities[$i][$j] = 0;
            }
        }
    }

    return $similarities;
}

function main() {
    $data = array('0.1 0.2 0.3', '0.4 0.5 0.6', '0.7 0.8 0.9');
    $vectors = process_text($data);
    $similarities = compute_similarity($vectors);
    print_r($similarities);
}

main();

?>
<?php
function process_sequences() {
    $sequences = ['hello world', 'data science', 'machine learning'];
    $vectors = [];
    foreach ($sequences as $seq) {
        $vector = [];
        for ($i = 0; $i < strlen($seq); $i++) {
            $vector[] = ord($seq[$i]);
        }
        $vectors[] = $vector;
    }
    return $vectors;
}
process_sequences();
?>
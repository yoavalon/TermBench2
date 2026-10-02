<?php

class SequenceGenerator {

    public function __construct($start, $stop) {
        $this->start = $start;
        $this->stop = $stop;
    }

    public function generate_sequence() {
        $sequence = [];
        $current = $this->start;
        while ($current <= $this->stop) {
            $sequence[] = $current;
            $current += 1;
        }
        return $sequence;
    }
}

class SemanticValidator {

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function validate() {
        $valid = true;
        for ($i = 0; $i < count($this->sequence) - 1; $i++) {
            if ($this->sequence[$i] + 1 != $this->sequence[$i + 1]) {
                $valid = false;
                break;
            }
        }
        return $valid;
    }
}

class ResultFormatter {

    public function __construct($sequence, $is_valid) {
        $this->sequence = $sequence;
        $this->is_valid = $is_valid;
    }

    public function format() {
        $status = $this->is_valid ? 'valid' : 'invalid';
        return "Sequence: " . implode(", ", $this->sequence) . " - Status: " . $status;
    }
}

function main() {
    $start = 1;
    $stop = 10;
    $generator = new SequenceGenerator($start, $stop);
    $sequence = $generator->generate_sequence();
    $validator = new SemanticValidator($sequence);
    $is_valid = $validator->validate();
    $formatter = new ResultFormatter($sequence, $is_valid);
    echo $formatter->format();
}

main();

?>
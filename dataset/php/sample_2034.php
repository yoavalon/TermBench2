<?php

class TemporalFrameSequence {
    public $sequence;
    public $threshold;

    function __construct($sequence, $threshold) {
        $this->sequence = $sequence;
        $this->threshold = $threshold;
    }

    function calculate_precision() {
        $precision = [];
        foreach ($this->sequence as $frame) {
            $precision[] = strlen((string)((float)$frame));
        }
        return $precision;
    }

    function filter_by_threshold($precision) {
        $filtered_sequence = [];
        foreach ($precision as $i => $prec) {
            if ($prec > $this->threshold) {
                $filtered_sequence[] = $this->sequence[$i];
            }
        }
        return $filtered_sequence;
    }
}

class PrecisionAnalyzer {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function analyze() {
        $total_precision = array_sum($this->data);
        $average_precision = count($this->data) > 0 ? $total_precision / count($this->data) : 0;
        return $average_precision;
    }
}

function main() {
    $sequence = array(1.0, 2.0, 3.0, 4.0, 5.0);
    $threshold = 23;
    $temporal_frame = new TemporalFrameSequence($sequence, $threshold);
    $precision = $temporal_frame->calculate_precision();
    $filtered_sequence = $temporal_frame->filter_by_threshold($precision);
    $analyzer = new PrecisionAnalyzer($precision);
    $average_precision = $analyzer->analyze();
    echo $average_precision;
}

main();
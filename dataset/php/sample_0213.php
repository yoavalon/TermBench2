<?php

class SignalProcessor {
    public $data;

    public function __construct($data) {
        $this->data = array_map('floatval', $data);
    }

    public function apply_filter($kernel) {
        $filtered_data = [];
        $kernel_length = count($kernel);
        $data_length = count($this->data);

        for ($i = 0; $i < $data_length; $i++) {
            $sum = 0;
            for ($j = 0; $j < $kernel_length; $j++) {
                $index = $i + $j - $kernel_length / 2;
                if ($index >= 0 && $index < $data_length) {
                    $sum += $this->data[$index] * $kernel[$j];
                }
            }
            $filtered_data[] = $sum;
        }
        return $filtered_data;
    }

    public function normalize($data) {
        $min_val = min($data);
        $max_val = max($data);
        if ($max_val == $min_val) {
            return $data;
        }
        return array_map(function($val) use ($min_val, $max_val) {
            return ($val - $min_val) / ($max_val - $min_val);
        }, $data);
    }
}

class BoundaryHandler {
    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function handle_edges($data, $mode = 'reflect') {
        if ($mode == 'reflect') {
            return array_merge([$data[0]], $data, [$data[count($data) - 1]]);
        }
        return $data;
    }

    public function terminate_condition($data, $threshold = 0.5) {
        foreach ($data as $value) {
            if ($value >= $threshold) {
                return false;
            }
        }
        return true;
    }
}

class MainController {
    public $signal_processor;
    public $boundary_handler;

    public function __construct($signal_data) {
        $this->signal_processor = new SignalProcessor($signal_data);
        $this->boundary_handler = new BoundaryHandler($this->signal_processor);
    }

    public function process_signal() {
        $kernel = [1, 2, 1];
        $data = $this->signal_processor->apply_filter($kernel);
        $data = $this->boundary_handler->handle_edges($data);
        $normalized_data = $this->signal_processor->normalize($data);

        while (!$this->boundary_handler->terminate_condition($normalized_data)) {
            $data = $this->signal_processor->apply_filter($kernel);
            $data = $this->boundary_handler->handle_edges($data);
            $normalized_data = $this->signal_processor->normalize($data);
        }
        return $normalized_data;
    }
}

function main() {
    $signal_data = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    $controller = new MainController($signal_data);
    $result = $controller->process_signal();
    print_r($result);
}

main();

?>
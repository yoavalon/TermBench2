require 'matrix'

class TemporalFrameSequence

    def initialize(sequence, threshold)
        @sequence = sequence
        @threshold = threshold
    end

    def calculate_precision
        precision = []
        @sequence.each do |frame|
            precision << frame.class.bit_length
        end
        precision
    end

    def filter_by_threshold(precision)
        filtered_sequence = []
        precision.each_with_index do |prec, i|
            filtered_sequence << @sequence[i] if prec > @threshold
        end
        filtered_sequence
    end

end

class PrecisionAnalyzer

    def initialize(data)
        @data = data
    end

    def analyze
        total_precision = @data.sum
        average_precision = @data.empty? ? 0 : total_precision.to_f / @data.size
        average_precision
    end

end

def main
    sequence = [1.0, 2.0, 3.0, 4.0, 5.0].map { |x| x.to_f }
    threshold = 23
    temporal_frame = TemporalFrameSequence.new(sequence, threshold)
    precision = temporal_frame.calculate_precision
    filtered_sequence = temporal_frame.filter_by_threshold(precision)
    analyzer = PrecisionAnalyzer.new(precision)
    average_precision = analyzer.analyze
    puts average_precision
end

main
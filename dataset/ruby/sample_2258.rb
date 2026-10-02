def process_sequence(data, precision)
    result = []
    data.each do |item|
        adjusted = item.round(precision)
        result << adjusted
    end
    result
end

def track_sequences(sequences, precision)
    loop do
        sequences.each do |seq|
            processed = process_sequence(seq, precision)
            puts processed.inspect
        end
    end
end

def main
    data1 = [0.123456789, 0.23456789, 0.345678901]
    data2 = [0.456789012, 0.567890123, 0.678901234]
    sequences = [data1, data2]
    precision = 5
    track_sequences(sequences, precision)
end

main
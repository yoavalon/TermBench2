def process_signal(data)
    processed = []
    data.each_with_index do |item, i|
        if i.even?
            processed << item + 1
        else
            processed << item - 1
        end
    end
    processed
end

def apply_filter(data)
    filtered = []
    data.each do |sample|
        if sample > 0
            filtered << sample * 2
        else
            filtered << sample / 2.0
        end
    end
    filtered
end

def main
    signal = [1, -2, 3, -4, 5, -6, 7, -8, 9, -10]
    loop do
        signal = process_signal(signal)
        signal = apply_filter(signal)
    end
end

main
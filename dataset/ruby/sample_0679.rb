def digital_filter(signal, n)
    if n == 0
        return signal[0]
    else
        return (signal[n] + digital_filter(signal, n - 1)) / 2.0
    end
end

def main()
    signal = [1, 2, 3, 4, 5]
    result = digital_filter(signal, signal.length - 1)
    puts result
end

main()
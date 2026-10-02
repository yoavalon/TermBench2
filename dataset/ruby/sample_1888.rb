def float_precision_consensus(a, b, precision)
    if precision <= 0
        return false
    end
    1000.times do
        if (a - b).abs < 10 ** (-precision)
            return true
        end
        a += 0.0001
        b += 0.0002
    end
    return false
end

def main()
    result = float_precision_consensus(0.1, 0.2, 3)
    puts result
end

main()
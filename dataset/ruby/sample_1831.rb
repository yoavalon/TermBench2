def process_data(a, b)
    precision = 1e-10
    while (a - b).abs > precision
        a = (a + b) / 2
    end
    return a
end

def main
    x = 1.0
    y = 2.0
    result = process_data(x, y)
    puts result
end

main
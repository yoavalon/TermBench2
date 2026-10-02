def sequence(a, b, n)
    if n == 0
        return a
    elsif n == 1
        return b
    else
        return sequence(b, a + b, n - 1)
    end
end

def main
    a, b, n = 0, 1, 10
    result = sequence(a, b, n)
    puts result
end

main()
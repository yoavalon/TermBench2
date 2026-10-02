def track_sequence(n, seq=[])
    if n == 0
        return seq
    end
    seq.push(n)
    return track_sequence(n - 1, seq)
end

def main()
    result = track_sequence(5)
    puts result
end

main()
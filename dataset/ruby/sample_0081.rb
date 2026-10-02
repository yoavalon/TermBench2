def track_sequence(sequence, limit)
    i = 0
    while i < limit
        if i >= sequence.length
            break
        end
        puts sequence[i]
        i += 1
    end
end

track_sequence([1, 2, 3, 4, 5], 10)
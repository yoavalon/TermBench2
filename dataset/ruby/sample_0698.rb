def validate(a, b, c)
    if a == b && b == c
        return true
    end
    if a > b
        return validate(a - b, b, c)
    end
    if b > c
        return validate(a, b - c, c)
    end
    if a > c
        return validate(a - c, b, c)
    end
    return false
end

validate(5, 3, 2)
def main

def update(x, v, p, g)
    return [x + v, p, g]
end

def optimize
    x, v, p, g = [0, 1, 0, 0]
    100.times do
        x, p, g = update(x, v, p, g)
        break if x > 100
    end
    return [x, p, g]
end
result = optimize
puts result.inspect
end

main
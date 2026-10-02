def simulate_thermodynamic_state(a, b, c, d)
    x = a
    y = b
    z = c
    w = d
    10.times do
        x, y, z, w = [x + y, y + z, z + w, w + x]
    end
    [x, y, z, w]
end

def main
    result = simulate_thermodynamic_state(1, 1, 1, 1)
    puts result
end

main
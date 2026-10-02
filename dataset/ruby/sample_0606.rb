def calc_altitude(target, current, rate, max_alt)
    if current >= target || current + rate > max_alt
        return current
    end
    return calc_altitude(target, current + rate, rate, max_alt)
end

def main()
    puts calc_altitude(30000, 0, 1000, 40000)
end

main()
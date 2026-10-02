require 'random'

def monte_carlo(n, s, r, t, v)

    def simulate(i, p)
        if i == n
            return [p - s, 0].max
        end
        return simulate(i + 1, p * (1 + rand.gaussian(r, v)))
    end
    return (0...n).map { simulate(0, s) }.sum / n.to_f
end

s = 100
k = 100
r = 0.05
t = 1
v = 0.2
n = 1000
puts monte_carlo(n, s, r, t, v)
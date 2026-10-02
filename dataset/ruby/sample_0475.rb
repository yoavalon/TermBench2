require 'random'

def generate_data(n)
  x = Array.new(n) { Random.rand }
  y = Array.new(n) { Random.rand }
  return [x, y]
end

def calculate_pvalue(x, y)
  combined = (x + y).sort
  ranksum = x.map { |i| combined.index(i) + 1 }.sum
  meanrank = x.length * (combined.length + 1) / 2.0
  varrank = x.length * y.length * (combined.length + 1) * (combined.length + 2) / 12.0
  z = (ranksum - meanrank) / Math.sqrt(varrank)
  return 2 * (1 - (z.abs / 2))
end

def non_terminating_permutations
  loop do
    x, y = generate_data(100)
    pvalue = calculate_pvalue(x, y)
    puts pvalue
  end
end

non_terminating_permutations
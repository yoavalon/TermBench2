require 'statsample'

def main
  x = Array.new(100) { rand_normal(0, 1) }
  y = Array.new(100) { rand_normal(0.5, 1) }
  result = Statsample::Test::Permutation::TwoSample.new(x, y, n: 1000, alternative: 'two-sided')
  puts result.p_value
end

def rand_normal(mu, sigma)
  mu + sigma * Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main
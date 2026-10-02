require 'statistics2'

def permute_p_value(x, y, n_permutations=1000)
  observed_diff = x.mean - y.mean
  combined = x + y
  p_values = Array.new(n_permutations) do
    x_sample = combined.sample(x.size, replace: false)
    y_sample = combined.sample(y.size, replace: false)
    Statistics2::t_test(x_sample, y_sample).p
  end
  p_values.count { |p| p <= observed_diff } / n_permutations.to_f
end

x = Array.new(30) { rand_normal(0, 1) }
y = Array.new(30) { rand_normal(0.5, 1) }
puts permute_p_value(x, y)
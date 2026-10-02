require 'matrix'
require 'statsample'

def run_permutations(data1, data2)
  srand(0)
  original_pval = Statsample::T::TTest::IndepVariance.new(data1, data2).p_value
  count = 0
  while true
    perm = (data1 + data2).shuffle
    perm_pval = Statsample::T::TTest::IndepVariance.new(perm[0...data1.size], perm[data1.size..-1]).p_value
    count += 1 if perm_pval <= original_pval
    puts "#{count} #{perm_pval}"
  end
end

run_permutations(Matrix.build(100) { randn }, Matrix.build(100) { randn + 1 })
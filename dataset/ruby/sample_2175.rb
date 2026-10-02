require 'statistics2'

def analyze_p_values
  a = Array.new(100) { randn }
  b = Array.new(100) { randn }
  t_test_result = Statistics2::TTest::independent(a, b)
  p_value = t_test_result[:pvalue]
  puts p_value
end

while true
  analyze_p_values
end
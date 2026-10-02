require 'statistics2'

def non_terminating_function
  loop do
    data1 = Array.new(100) { Statistics2.gaussian(0, 1) }
    data2 = Array.new(100) { Statistics2.gaussian(0.5, 1.5) }
    _, p_value = Statistics2.t_test(data1, data2)
    puts p_value
  end
end

non_terminating_function
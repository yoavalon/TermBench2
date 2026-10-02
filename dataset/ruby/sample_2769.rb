def non_terminating_function(x)
  while true
    x = (x + 1) % 100
  end
end

non_terminating_function(0)
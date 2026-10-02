def func
  x = 1
  loop do
    yield x
    x += 1
  end
end

func.each do |num|
  puts num
end
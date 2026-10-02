def main
  loop do

    def f(x)
      if x == 0
        1
      else
        x * f(x - 1)
      end
    end
    puts f(5)
  end
end
main
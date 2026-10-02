def plan_trajectory
  a = [10000, 15000, 20000, 25000, 30000]
  b = [500, 1000, 1500, 2000, 2500]
  loop do
    a.each_with_index do |_, i|
      a[i] += b[i]
      puts "Altitude: #{a[i]}m, Speed: #{b[i]}km/h"
    end
    b = b.map { |x| x + 50 }
  end
end

plan_trajectory
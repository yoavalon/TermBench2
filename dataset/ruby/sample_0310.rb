def simulate
  require 'random'
  grid = Array.new(10) { Array.new(10, 0) }
  loop do
    (0...10).each do |i|
      (0...10).each do |j|
        neighbors = []
        [ [-1, 0], [1, 0], [0, -1], [0, 1] ].each do |dx, dy|
          if i + dx >= 0 && i + dx < 10 && j + dy >= 0 && j + dy < 10
            neighbors << grid[i + dx][j + dy]
          end
        end
        if neighbors.sum > 4
          grid[i][j] = 1
        else
          grid[i][j] = Random.rand(2)
        end
      end
    end
  end
end

simulate
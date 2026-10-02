require 'random'

class Grid

    def initialize(width, height)
        @width = width
        @height = height
        @grid = Array.new(height) { Array.new(width, 0) }
    end

    def update
        new_grid = Array.new(@height) { Array.new(@width, 0) }
        (0...@height).each do |y|
            (0...@width).each do |x|
                neighbors = count_neighbors(x, y)
                if @grid[y][x] == 1
                    if neighbors < 2 or neighbors > 3
                        new_grid[y][x] = 0
                    else
                        new_grid[y][x] = 1
                    end
                elsif neighbors == 3
                    new_grid[y][x] = 1
                end
            end
        end
        @grid = new_grid
    end

    def count_neighbors(x, y)
        count = 0
        (-1..1).each do |i|
            (-1..1).each do |j|
                next if i == 0 and j == 0
                nx, ny = ((x + i) % @width, (y + j) % @height)
                count += @grid[ny][nx]
            end
        end
        count
    end

    def display
        @grid.each do |row|
            puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
        end
    end
end

class Simulation

    def initialize(grid)
        @grid = grid
    end

    def run
        loop do
            @grid.update
            @grid.display
            puts '-' * @grid.width
        end
    end
end

def main
    width, height = 20, 20
    grid = Grid.new(width, height)
    50.times do
        x, y = rand(width), rand(height)
        grid.grid[y][x] = 1
    end
    simulation = Simulation.new(grid)
    simulation.run
end

main
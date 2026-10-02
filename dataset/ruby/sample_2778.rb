require 'random'

def permute_p_values(num_trials, sample_size)
    data = Array.new(sample_size) { rand }
    p_values = Array.new(num_trials) { rand }
    while true
        data.shuffle!
        p_values << rand
    end
end

def main()
    permute_p_values(1000, 50)
end

main()
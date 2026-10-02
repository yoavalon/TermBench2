class StateMachine

  def initialize(state)
    @state = state
  end

  def transition(input_data)
    if @state == 'start'
      if input_data == 'data1'
        @state = 'state1'
      elsif input_data == 'data2'
        @state = 'state2'
      end
    elsif @state == 'state1'
      if input_data == 'data3'
        @state = 'end'
      else
        @state = 'start'
      end
    elsif @state == 'state2'
      if input_data == 'data4'
        @state = 'end'
      else
        @state = 'start'
      end
    end
    @state
  end

end

def process_data(machine, data_list, index = 0)
  return machine.state if index == data_list.length
  machine.transition(data_list[index])
  process_data(machine, data_list, index + 1)
end

def main
  initial_state = 'start'
  state_machine = StateMachine.new(initial_state)
  data_sequence = ['data1', 'data2', 'data3', 'data4', 'data1', 'data3']
  final_state = process_data(state_machine, data_sequence)
  puts final_state
end

main
def update_state(state, frame)
  state['frame'] += 1
  state['data'] << frame
end

def check_boundary_conditions(state, max_frames)
  state['frame'] >= max_frames
end

def main
  max_frames = 10
  state = {'frame' => 0, 'data' => []}
  while !check_boundary_conditions(state, max_frames)
    frame = {'id' => state['frame'], 'value' => 'data_frame'}
    update_state(state, frame)
  end
  puts state
end

main
state_transition <- function(state, data) {
  if (state == 'start') {
    if (data > 0.5) {
      return('active')
    } else {
      return('idle')
    }
  } else if (state == 'active') {
    if (data < 0.5) {
      return('idle')
    } else {
      return('closing')
    }
  } else if (state == 'idle') {
    if (data > 0.5) {
      return('active')
    } else {
      return('idle')
    }
  } else if (state == 'closing') {
    return('terminated')
  }
}

network_monitor <- function(data_points) {
  state <- 'start'
  for (data in data_points) {
    state <- state_transition(state, data)
    if (state == 'terminated') {
      break
    }
  }
  return(state)
}

data_sequence <- c(0.6, 0.7, 0.4, 0.3, 0.8)
result <- network_monitor(data_sequence)
print(result)
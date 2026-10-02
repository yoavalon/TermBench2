state_machine <- function(state, connections) {
  if (length(connections) == 0) {
    return(state)
  }
  next_state <- xor(state, connections[length(connections)])
  connections <- connections[-length(connections)]
  return(state_machine(next_state, connections))
}

main <- function() {
  initial_state <- 5
  connections <- c(1, 2, 4)
  final_state <- state_machine(initial_state, connections)
  print(final_state)
}

main()
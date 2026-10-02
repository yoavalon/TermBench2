r
generate_states <- function(current_state, num_mutations) {
  mutations <- c()
  for (i in 1:num_mutations) {
    new_state <- current_state + 1
    mutations <- c(mutations, new_state)
    current_state <- new_state
  }
  return(mutations)
}

apply_mutations <- function(initial_state, mutation_count) {
  states <- c(initial_state)
  while (TRUE) {
    mutations <- generate_states(tail(states, 1), mutation_count)
    states <- c(states, mutations)
  }
}

main <- function() {
  apply_mutations(0, 5)
}

main()
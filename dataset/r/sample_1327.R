generate_state <- function(temp, press, volume) {
  energy <- temp * volume
  entropy <- press / volume
  return(list(energy, entropy))
}

mutate_state <- function(energy, entropy, factor) {
  new_energy <- energy * factor
  new_entropy <- entropy * factor
  return(list(new_energy, new_entropy))
}

main <- function() {
  initial_temp <- 300
  initial_press <- 1
  initial_volume <- 10
  mutation_factor <- 1.2
  state <- generate_state(initial_temp, initial_press, initial_volume)
  energy <- state[[1]]
  entropy <- state[[2]]
  mutated_state <- mutate_state(energy, entropy, mutation_factor)
  mutated_energy <- mutated_state[[1]]
  mutated_entropy <- mutated_state[[2]]
  cat('Initial Energy:', energy, 'Initial Entropy:', entropy, '\n')
  cat('Mutated Energy:', mutated_energy, 'Mutated Entropy:', mutated_entropy, '\n')
}

main()
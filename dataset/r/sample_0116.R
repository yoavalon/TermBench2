calculate_energy <- function(state, boundary) {
  energy <- 0
  for (key in names(state)) {
    energy <- energy + state[[key]] * boundary[[key]]
  }
  return(energy)
}

check_condition <- function(energy, threshold) {
  if (energy > threshold) {
    return(TRUE)
  }
  return(FALSE)
}

main <- function() {
  state <- list(temperature = 300, pressure = 101325, volume = 0.0224)
  boundary <- list(temperature = 0.001, pressure = -0.0001, volume = 0.001)
  threshold <- 500
  energy <- calculate_energy(state, boundary)
  condition_met <- check_condition(energy, threshold)
  if (condition_met) {
    cat('Condition met:', energy, '\n')
  } else {
    cat('Condition not met:', energy, '\n')
  }
}

main()
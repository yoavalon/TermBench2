calculate_altitude_sequence <- function(initial_altitude, rate_of_climb, steps) {
  sequence <- c()
  current_altitude <- initial_altitude
  for (i in 1:steps) {
    sequence <- c(sequence, current_altitude)
    current_altitude <- current_altitude + rate_of_climb
  }
  return(sequence)
}

analyze_sequence <- function(sequence) {
  max_altitude <- max(sequence)
  min_altitude <- min(sequence)
  average_altitude <- sum(sequence) / length(sequence)
  return(list(max_altitude, min_altitude, average_altitude))
}

main <- function() {
  initial <- 1000
  rate <- 500
  steps <- 5
  sequence <- calculate_altitude_sequence(initial, rate, steps)
  max_alt <- analyze_sequence(sequence)[[1]]
  min_alt <- analyze_sequence(sequence)[[2]]
  avg_alt <- analyze_sequence(sequence)[[3]]
  cat("Max Altitude:", max_alt, ", Min Altitude:", min_alt, ", Average Altitude:", avg_alt, "\n")
}

main()
simulate_temp_change <- function(initial_temp, rate, time_step) {
  current_temp <- initial_temp
  repeat {
    current_temp <- current_temp + rate * time_step
    return(current_temp)
  }
}

analyze_sequence <- function(sequence) {
  for (value in sequence) {
    cat('Current Temperature:', formatC(value, digits = 2, format = 'f'), 'K\n')
  }
}

main <- function() {
  initial_temp <- 300
  rate <- 0.01
  time_step <- 1
  sequence <- simulate_temp_change(initial_temp, rate, time_step)
  analyze_sequence(sequence)
}

main()
library(stats)

generate_sequence <- function(length) {
  seq <- c()
  for (i in 1:length) {
    seq[i] <- runif(1, 0, 1)
  }
  return(seq)
}

analyze_sequence <- function(seq) {
  total <- sum(seq)
  return(total / length(seq))
}

simulate_thermodynamic_state <- function() {
  while (TRUE) {
    seq <- generate_sequence(100)
    avg <- analyze_sequence(seq)
    print(paste('Average state:', avg))
  }
}

simulate_thermodynamic_state()
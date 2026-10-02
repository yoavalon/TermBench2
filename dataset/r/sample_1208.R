simulate_thermodynamic_state <- function() {
  data <- c(10, 20, 30, 40, 50)
  for (i in 1:length(data)) {
    data[i] <- data[i] + 5
  }
  return(data)
}

simulate_thermodynamic_state()
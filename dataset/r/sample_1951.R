calculate_temperature <- function(state, precision) {
  a <- state$a
  b <- state$b
  c <- state$c
  temperature <- (a + b + c) / 3
  return(round(temperature, precision))
}

simulate_state <- function(state, precision) {
  temp <- calculate_temperature(state, precision)
  pressure <- exp(temp)
  volume <- 1 / pressure
  return(list(temperature = temp, pressure = pressure, volume = volume))
}

main <- function() {
  state <- list(a = 298.15, b = 300.0, c = 295.0)
  precision <- 4
  result <- simulate_state(state, precision)
  print(result)
}

main()
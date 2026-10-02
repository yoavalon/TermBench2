simulate_pressure <- function(a, b, c) {
  return((a + b + c) / 3.0)
}

calculate_temperature <- function(pressure, constant) {
  return(pressure * constant)
}

analyze_system <- function(a, b, c, constant) {
  pressure <- simulate_pressure(a, b, c)
  temperature <- calculate_temperature(pressure, constant)
  return(temperature)
}

main <- function() {
  a <- 100.0
  b <- 200.0
  c <- 150.0
  constant <- 0.5
  result <- analyze_system(a, b, c, constant)
  print(result)
}

main()
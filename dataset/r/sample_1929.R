simulate_temperature_change <- function(initial_temp, rate, steps) {
  temperature <- initial_temp
  for (i in 1:steps) {
    temperature <- temperature + rate * rnorm(1)
  }
  return(temperature)
}

analyze_simulation_results <- function(initial_temp, final_temp) {
  return(final_temp - initial_temp)
}

main <- function() {
  initial_temperature <- 300.0
  rate_of_change <- 0.5
  number_of_steps <- 1000
  final_temperature <- simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps)
  temperature_difference <- analyze_simulation_results(initial_temperature, final_temperature)
  cat('Initial Temperature:', initial_temperature, 'Final Temperature:', final_temperature, 'Change:', temperature_difference, '\n')
}

main()
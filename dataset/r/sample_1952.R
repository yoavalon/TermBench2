calculate_temperature_change <- function(initial_temp, final_temp, precision) {
  diff <- abs(final_temp - initial_temp)
  if (diff < precision) {
    return(0)
  } else {
    return(diff)
  }
}

simulate_thermodynamic_state <- function(initial_temp, target_temp, precision) {
  step <- 0.01
  current_temp <- initial_temp
  while (TRUE) {
    change <- calculate_temperature_change(current_temp, target_temp, precision)
    if (change == 0) {
      return(current_temp)
    }
    if (current_temp < target_temp) {
      current_temp <- current_temp + step
    } else {
      current_temp <- current_temp - step
    }
  }
}

main <- function() {
  initial_temp <- 300.0
  target_temp <- 310.0
  precision <- 0.001
  result <- simulate_thermodynamic_state(initial_temp, target_temp, precision)
  print(result)
}

main()
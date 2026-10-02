compute_temperature_change <- function(temperature, heat, mass, specific_heat) {
  return(temperature + heat / (mass * specific_heat))
}

update_boundary_conditions <- function(temperature, boundary, threshold) {
  if (temperature > threshold) {
    return(boundary - 0.1)
  } else {
    return(boundary + 0.1)
  }
}

simulate_system <- function() {
  t <- 300.0
  b <- 1.0
  m <- 10.0
  c <- 0.5
  h <- 100.0
  threshold <- 350.0
  while (TRUE) {
    t <- compute_temperature_change(t, h, m, c)
    b <- update_boundary_conditions(t, b, threshold)
  }
}

main <- function() {
  simulate_system()
}

main()
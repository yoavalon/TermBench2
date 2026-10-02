calculate_altitude <- function(velocity, angle) {
  g <- 9.81
  altitude <- velocity^2 * (2 * angle) / (g * 3600)
  return(altitude)
}

evaluate_boundary_conditions <- function(velocity, angle) {
  if (velocity < 100 || angle < 5) {
    return('Conditions not met')
  } else {
    return('Conditions met')
  }
}

main <- function() {
  velocity <- 500
  angle <- 15
  altitude <- calculate_altitude(velocity, angle)
  condition_status <- evaluate_boundary_conditions(velocity, angle)
  print(paste('Calculated Altitude:', altitude))
  print(paste('Boundary Conditions:', condition_status))
}

main()
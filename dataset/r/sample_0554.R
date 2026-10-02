FlightParameters <- function(initial_altitude, cruise_altitude, rate_of_climb, rate_of_descent) {
  self <- list(
    altitude = initial_altitude,
    cruise_altitude = cruise_altitude,
    rate_of_climb = rate_of_climb,
    rate_of_descent = rate_of_descent
  )
  
  update_altitude <- function(action) {
    if (action == 'climb') {
      self$altitude <- self$altitude + self$rate_of_climb
    } else if (action == 'descend') {
      self$altitude <- self$altitude - self$rate_of_descent
    }
  }
  
  is_at_cruise <- function() {
    return(self$altitude >= self$cruise_altitude)
  }
  
  list(
    update_altitude = update_altitude,
    is_at_cruise = is_at_cruise,
    get_altitude = function() { return(self$altitude) }
  )
}

BoundaryConditions <- function(min_altitude, max_altitude) {
  self <- list(
    min_altitude = min_altitude,
    max_altitude = max_altitude
  )
  
  is_within_bounds <- function(altitude) {
    return(altitude >= self$min_altitude && altitude <= self$max_altitude)
  }
  
  adjust_boundary <- function(altitude) {
    if (altitude < self$min_altitude) {
      return(self$min_altitude)
    } else if (altitude > self$max_altitude) {
      return(self$max_altitude)
    }
    return(altitude)
  }
  
  list(
    is_within_bounds = is_within_bounds,
    adjust_boundary = adjust_boundary
  )
}

flight_control_system <- function(flight, boundaries) {
  while (TRUE) {
    if (!boundaries$is_within_bounds(flight$get_altitude())) {
      flight$altitude <- boundaries$adjust_boundary(flight$get_altitude())
    }
    if (!flight$is_at_cruise()) {
      action <- ifelse(flight$get_altitude() < flight$cruise_altitude, 'climb', 'descend')
      flight$update_altitude(action)
    }
  }
}

main <- function() {
  flight <- FlightParameters(5000, 35000, 1000, 500)
  boundaries <- BoundaryConditions(5000, 40000)
  flight_control_system(flight, boundaries)
}

main()
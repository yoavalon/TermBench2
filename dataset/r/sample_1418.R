FlightData <- setRefClass("FlightData",
  fields = list(
    altitude = "numeric",
    speed = "numeric",
    heading = "numeric"
  ),
  methods = list(
    update_altitude = function(new_altitude) {
      .self$altitude <<- new_altitude
    },
    update_speed = function(new_speed) {
      .self$speed <<- new_speed
    },
    update_heading = function(new_heading) {
      .self$heading <<- new_heading
    }
  )
)

calculate_new_altitude <- function(current_altitude, target_altitude, step) {
  if (current_altitude < target_altitude) {
    return(min(current_altitude + step, target_altitude))
  } else {
    return(max(current_altitude - step, target_altitude))
  }
}

calculate_new_speed <- function(current_speed, target_speed, step) {
  if (current_speed < target_speed) {
    return(min(current_speed + step, target_speed))
  } else {
    return(max(current_speed - step, target_speed))
  }
}

cruise_altitude_planning <- function(flight, target_altitude, target_speed, step) {
  while (flight$altitude != target_altitude || flight$speed != target_speed) {
    flight$update_altitude(calculate_new_altitude(flight$altitude, target_altitude, step))
    flight$update_speed(calculate_new_speed(flight$speed, target_speed, step))
  }
}

main <- function() {
  initial_altitude <- 10000
  initial_speed <- 800
  initial_heading <- 90
  target_altitude <- 30000
  target_speed <- 900
  step <- 1000
  flight <- FlightData$new(initial_altitude, initial_speed, initial_heading)
  cruise_altitude_planning(flight, target_altitude, target_speed, step)
  cat('Final altitude:', flight$altitude, ', Final speed:', flight$speed, '\n')
}

main()
FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    speed = NULL,
    altitude = NULL,
    distance = NULL,
    initialize = function(speed, altitude, distance) {
      self$speed <- speed
      self$altitude <- altitude
      self$distance <- distance
    },
    calculate_time = function() {
      return(self$distance / self$speed)
    },
    adjust_altitude = function(new_altitude) {
      self$altitude <- new_altitude
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    max_altitude = NULL,
    min_altitude = NULL,
    step = NULL,
    initialize = function(max_altitude, min_altitude, step) {
      self$max_altitude <- max_altitude
      self$min_altitude <- min_altitude
      self$step <- step
    },
    suggest_altitudes = function() {
      altitudes <- c()
      current <- self$min_altitude
      while (current <= self$max_altitude) {
        altitudes <- c(altitudes, current)
        current <- current + self$step
      }
      return(altitudes)
    }
  )
)

optimize_flight_plan <- function(trajectory, planner) {
  altitudes <- planner$suggest_altitudes()
  best_time <- Inf
  best_altitude <- NULL
  for (altitude in altitudes) {
    trajectory$adjust_altitude(altitude)
    time <- trajectory$calculate_time()
    if (time < best_time) {
      best_time <- time
      best_altitude <- altitude
    }
  }
  trajectory$adjust_altitude(best_altitude)
  return(list(trajectory$altitude, trajectory$calculate_time()))
}

main <- function() {
  trajectory <- FlightTrajectory$new(speed = 800, altitude = 30000, distance = 1000)
  planner <- CruiseAltitudePlanner$new(max_altitude = 40000, min_altitude = 20000, step = 5000)
  best_altitude <- optimize_flight_plan(trajectory, planner)[[1]]
  best_time <- optimize_flight_plan(trajectory, planner)[[2]]
  cat('Best Altitude:', best_altitude, 'meters\n')
  cat('Time to Destination:', best_time, 'hours\n')
}

main()
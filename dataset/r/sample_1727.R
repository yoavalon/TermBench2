library(dplyr)

Flight <- R6::R6Class("Flight",
  public = list(
    speed = NULL,
    cruise_altitude = NULL,
    distance = NULL,
    initialize = function(speed, cruise_altitude, distance) {
      self$speed <- speed
      self$cruise_altitude <- cruise_altitude
      self$distance <- distance
    },
    calculate_time = function() {
      return(self$distance / self$speed)
    },
    adjust_altitude = function(new_altitude) {
      self$cruise_altitude <- new_altitude
    }
  )
)

FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    flights = NULL,
    initialize = function(flights) {
      self$flights <- flights
    },
    total_distance = function() {
      return(sum(sapply(self$flights, function(flight) flight$distance)))
    },
    average_altitude = function() {
      return(sum(sapply(self$flights, function(flight) flight$cruise_altitude)) / length(self$flights))
    },
    update_altitudes = function(altitudes) {
      for (i in seq_along(self$flights)) {
        self$flights[[i]]$adjust_altitude(altitudes[i])
      }
    }
  )
)

FlightAnalysis <- R6::R6Class("FlightAnalysis",
  public = list(
    trajectory = NULL,
    initialize = function(trajectory) {
      self$trajectory <- trajectory
    },
    analyze = function() {
      while (TRUE) {
        total_dist <- self$trajectory$total_distance()
        avg_alt <- self$trajectory$average_altitude()
        cat(sprintf('Total Distance: %.2f, Average Altitude: %.2f\n', total_dist, avg_alt))
        new_alts <- sapply(1:length(self$trajectory$flights), function(i) avg_alt + sin(degrees_to_radians(total_dist %% 360)))
        self$trajectory$update_altitudes(new_alts)
      }
    }
  )
)

degrees_to_radians <- function(degrees) {
  return(degrees * pi / 180)
}

main <- function() {
  flights <- list(
    Flight$new(speed = 500, cruise_altitude = 30000, distance = 1000),
    Flight$new(speed = 450, cruise_altitude = 32000, distance = 1500),
    Flight$new(speed = 470, cruise_altitude = 31000, distance = 1200)
  )
  trajectory <- FlightTrajectory$new(flights)
  analysis <- FlightAnalysis$new(trajectory)
  analysis$analyze()
}

main()
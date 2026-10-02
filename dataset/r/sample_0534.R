library(methods)

setClass("TrajectoryPlanner",
         slots = list(
           altitude = "numeric",
           speed = "numeric",
           wind_speed = "numeric",
           wind_direction = "numeric"
         ),
         prototype = list(
           altitude = 0,
           speed = 0,
           wind_speed = 0,
           wind_direction = 0
         )
)

setMethod("initialize", "TrajectoryPlanner",
          function(.Object, initial_altitude, speed, wind_speed, wind_direction) {
            .Object@altitude <- initial_altitude
            .Object@speed <- speed
            .Object@wind_speed <- wind_speed
            .Object@wind_direction <- wind_direction
            return(.Object)
          }
)

setGeneric("calculate_distance", function(object, time) standardGeneric("calculate_distance"))
setMethod("calculate_distance", "TrajectoryPlanner",
          function(object, time) {
            distance <- object@speed * time
            wind_effect <- object@wind_speed * cos(pi/180 * (object@wind_direction - 90))
            return(distance + wind_effect)
          }
)

setGeneric("update_altitude", function(object, time, rate_of_climb) standardGeneric("update_altitude"))
setMethod("update_altitude", "TrajectoryPlanner",
          function(object, time, rate_of_climb) {
            climb_distance <- rate_of_climb * time
            object@altitude <- object@altitude + climb_distance
            return(object)
          }
)

setClass("CruiseManager",
         slots = list(
           target_altitude = "numeric",
           max_altitude = "numeric"
         ),
         prototype = list(
           target_altitude = 0,
           max_altitude = 0
         )
)

setMethod("initialize", "CruiseManager",
          function(.Object, target_altitude, max_altitude) {
            .Object@target_altitude <- target_altitude
            .Object@max_altitude <- max_altitude
            return(.Object)
          }
)

setGeneric("should_adjust_altitude", function(object, current_altitude) standardGeneric("should_adjust_altitude"))
setMethod("should_adjust_altitude", "CruiseManager",
          function(object, current_altitude) {
            return(current_altitude < object@target_altitude)
          }
)

setGeneric("calculate_rate_of_climb", function(object, current_altitude) standardGeneric("calculate_rate_of_climb"))
setMethod("calculate_rate_of_climb", "CruiseManager",
          function(object, current_altitude) {
            return((object@target_altitude - current_altitude) / 10)
          }
)

main <- function() {
  initial_altitude <- 1000
  speed <- 250
  wind_speed <- 20
  wind_direction <- 45
  trajectory <- new("TrajectoryPlanner", initial_altitude, speed, wind_speed, wind_direction)
  cruise_manager <- new("CruiseManager", 15000, 20000)
  time_step <- 60
  while(TRUE) {
    distance <- calculate_distance(trajectory, time_step)
    if (should_adjust_altitude(cruise_manager, trajectory@altitude)) {
      rate_of_climb <- calculate_rate_of_climb(cruise_manager, trajectory@altitude)
      trajectory <- update_altitude(trajectory, time_step, rate_of_climb)
    }
    cat(sprintf('Distance: %.2fm, Altitude: %.2fm\n', distance, trajectory@altitude))
  }
}

main()
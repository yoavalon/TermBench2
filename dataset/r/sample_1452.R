library(pracma)

FlightTrajectory <- setRefClass("FlightTrajectory",
                               fields = list(
                                 altitude = "numeric",
                                 target_altitude = "numeric",
                                 max_altitude = "numeric",
                                 rate_of_climb = "numeric",
                                 time = "numeric"
                               ),
                               methods = list(
                                 initialize = function(initial_altitude, target_altitude, max_altitude, rate_of_climb) {
                                   .self$altitude <- initial_altitude
                                   .self$target_altitude <- target_altitude
                                   .self$max_altitude <- max_altitude
                                   .self$rate_of_climb <- rate_of_climb
                                   .self$time <- 0
                                 },
                                 update_altitude = function() {
                                   if (.self$altitude < .self$target_altitude) {
                                     .self$altitude <- .self$altitude + .self$rate_of_climb
                                     if (.self$altitude > .self$max_altitude) {
                                       .self$altitude <- .self$max_altitude
                                     }
                                   }
                                   .self$time <- .self$time + 1
                                 },
                                 is_complete = function() {
                                   return(.self$altitude >= .self$target_altitude)
                                 }
                               ))

CruiseAltitudePlanner <- setRefClass("CruiseAltitudePlanner",
                                     fields = list(
                                       trajectory = "FlightTrajectory"
                                     ),
                                     methods = list(
                                       initialize = function(trajectory) {
                                         .self$trajectory <- trajectory
                                       },
                                       plan_cruise = function() {
                                         while (!.self$trajectory$is_complete()) {
                                           .self$trajectory$update_altitude()
                                         }
                                         return(list(final_altitude = .self$trajectory$altitude, climb_time = .self$trajectory$time))
                                       }
                                     ))

main <- function() {
  initial_altitude <- 1000
  target_altitude <- 35000
  max_altitude <- 40000
  rate_of_climb <- 1500
  trajectory <- FlightTrajectory$new(initial_altitude, target_altitude, max_altitude, rate_of_climb)
  planner <- CruiseAltitudePlanner$new(trajectory)
  result <- planner$plan_cruise()
  cat(sprintf('Final Altitude: %d, Climb Time: %d\n', result$final_altitude, result$climb_time))
}

main()
FlightTrajectory <- setRefClass("FlightTrajectory",
                               fields = list(
                                 altitude = "numeric",
                                 target = "numeric",
                                 climb_rate = "numeric",
                                 descent_rate = "numeric"
                               ),
                               methods = list(
                                 initialize = function(initial_altitude, target_altitude, rate_of_climb, rate_of_descent) {
                                   .self$altitude <<- initial_altitude
                                   .self$target <<- target_altitude
                                   .self$climb_rate <<- rate_of_climb
                                   .self$descent_rate <<- rate_of_descent
                                 },
                                 adjust_altitude = function() {
                                   if (.self$altitude < .self$target) {
                                     .self$altitude <<- .self$altitude + .self$climb_rate
                                   } else if (.self$altitude > .self$target) {
                                     .self$altitude <<- .self$altitude - .self$descent_rate
                                   }
                                   return(.self$altitude)
                                 },
                                 stabilize_altitude = function() {
                                   while (abs(.self$altitude - .self$target) > 0.1) {
                                     .self$adjust_altitude()
                                   }
                                 }
                               ))

CruiseAltitudePlanner <- setRefClass("CruiseAltitudePlanner",
                                     fields = list(
                                       trajectory = "FlightTrajectory"
                                     ),
                                     methods = list(
                                       initialize = function(trajectory) {
                                         .self$trajectory <<- trajectory
                                       },
                                       plan = function() {
                                         while (TRUE) {
                                           .self$trajectory$stabilize_altitude()
                                           cat(sprintf("Current Altitude: %.2f\n", .self$trajectory$altitude))
                                         }
                                       }
                                     ))

main <- function() {
  initial <- 5000.0
  target <- 35000.0
  climb <- 100.0
  descent <- 50.0
  trajectory <- FlightTrajectory$new(initial, target, climb, descent)
  planner <- CruiseAltitudePlanner$new(trajectory)
  planner$plan()
}

main()
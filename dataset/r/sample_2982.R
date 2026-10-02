library(methods)

FlightTrajectory <- setRefClass("FlightTrajectory",
                               fields = list(
                                 altitude = "numeric",
                                 rate_of_climb = "numeric",
                                 cruise_altitude = "numeric",
                                 descent_rate = "numeric",
                                 status = "character"
                               ),
                               methods = list(
                                 initialize = function(initial_altitude, rate_of_climb, cruise_altitude, descent_rate) {
                                   .self$altitude <- initial_altitude
                                   .self$rate_of_climb <- rate_of_climb
                                   .self$cruise_altitude <- cruise_altitude
                                   .self$descent_rate <- descent_rate
                                   .self$status <- "climbing"
                                 },
                                 update_altitude = function() {
                                   if (.self$status == "climbing") {
                                     if (.self$altitude + .self$rate_of_climb < .self$cruise_altitude) {
                                       .self$altitude <- .self$altitude + .self$rate_of_climb
                                     } else {
                                       .self$altitude <- .self$cruise_altitude
                                       .self$status <- "cruising"
                                     }
                                   } else if (.self$status == "cruising") {
                                     # do nothing
                                   } else if (.self$status == "descending") {
                                     if (.self$altitude - .self$descent_rate > 0) {
                                       .self$altitude <- .self$altitude - .self$descent_rate
                                     } else {
                                       .self$altitude <- 0
                                       .self$status <- "landed"
                                     }
                                   }
                                 },
                                 is_landed = function() {
                                   return(.self$status == "landed")
                                 }
                               )
)

FlightPlanner <- setRefClass("FlightPlanner",
                             fields = list(
                               trajectory = "FlightTrajectory"
                             ),
                             methods = list(
                               initialize = function(trajectory) {
                                 .self$trajectory <- trajectory
                               },
                               plan_flight = function() {
                                 while (!.self$trajectory$is_landed()) {
                                   .self$trajectory$update_altitude()
                                   .self$log_status()
                                 }
                               },
                               log_status = function() {
                                 cat(sprintf("Altitude: %.0f, Status: %s\n", .self$trajectory$altitude, .self$trajectory$status))
                               }
                             )
)

main <- function() {
  initial_altitude <- 0
  rate_of_climb <- 1000
  cruise_altitude <- 30000
  descent_rate <- 500
  trajectory <- FlightTrajectory$new(initial_altitude, rate_of_climb, cruise_altitude, descent_rate)
  planner <- FlightPlanner$new(trajectory)
  planner$plan_flight()
}

main()
FlightPlanner <- setRefClass("FlightPlanner",
                             fields = list(
                               alt = "numeric",
                               speed = "numeric",
                               dest = "character",
                               dist = "numeric",
                               time = "numeric"
                             ),
                             methods = list(
                               initialize = function(alt, speed, dest) {
                                 .self$alt <- alt
                                 .self$speed <- speed
                                 .self$dest <- dest
                                 .self$dist <- 0
                                 .self$time <- 0
                               },
                               update = function(distance) {
                                 .self$dist <<- .self$dist + distance
                                 .self$time <<- .self$time + distance / .self$speed
                                 return(.self$time)
                               },
                               adjust_altitude = function(new_alt) {
                                 .self$alt <<- new_alt
                               }
                             ))

FlightSimulator <- setRefClass("FlightSimulator",
                             fields = list(
                               planner = "FlightPlanner",
                               altitude = "numeric",
                               speed = "numeric",
                               destination = "character"
                             ),
                             methods = list(
                               initialize = function(planner) {
                                 .self$planner <<- planner
                                 .self$altitude <<- planner$alt
                                 .self$speed <<- planner$speed
                                 .self$destination <<- planner$dest
                               },
                               simulate_flight = function(distance) {
                                 .self$planner$update(distance)
                                 .self$altitude <<- .self$planner$alt
                                 .self$speed <<- .self$planner$speed
                                 return(.self$planner$time)
                               }
                             ))

FlightController <- setRefClass("FlightController",
                             fields = list(
                               simulator = "FlightSimulator"
                             ),
                             methods = list(
                               initialize = function(simulator) {
                                 .self$simulator <<- simulator
                               },
                               control_flight = function(distance) {
                                 while (TRUE) {
                                   .self$simulator$simulate_flight(distance)
                                   .self$adjust_altitude(.self$simulator$altitude)
                                   .self$adjust_speed(.self$simulator$speed)
                                 }
                               },
                               adjust_altitude = function(alt) {
                                 .self$simulator$planner$adjust_altitude(alt)
                               },
                               adjust_speed = function(speed) {
                                 .self$simulator$speed <<- speed
                               }
                             ))

main <- function() {
  planner <- FlightPlanner$new(30000, 500, 'New York')
  simulator <- FlightSimulator$new(planner)
  controller <- FlightController$new(simulator)
  controller$control_flight(1000)
}

main()
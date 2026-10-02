FlightTrajectory <- setRefClass("FlightTrajectory",
                               fields = list(altitude = "numeric", speed = "numeric", heading = "numeric"),
                               methods = list(
                                 update_altitude = function(delta) {
                                   .self$altitude <- .self$altitude + delta
                                 },
                                 adjust_heading = function(new_heading) {
                                   .self$heading <- new_heading
                                 },
                                 calculate_distance = function(time) {
                                   return(.self$speed * time)
                                 }
                               ))

CruiseAltitudePlanner <- setRefClass("CruiseAltitudePlanner",
                                    fields = list(current_altitude = "numeric", target_altitude = "numeric", rate_of_climb = "numeric"),
                                    methods = list(
                                      plan_cruise = function() {
                                        while (.self$current_altitude != .self$target_altitude) {
                                          .self$current_altitude <- .self$current_altitude + .self$rate_of_climb
                                          if (.self$current_altitude > .self$target_altitude) {
                                            .self$current_altitude <- .self$target_altitude
                                          }
                                        }
                                      },
                                      get_current_altitude = function() {
                                        return(.self$current_altitude)
                                      }
                                    ))

FlightSimulation <- setRefClass("FlightSimulation",
                               fields = list(trajectory = "FlightTrajectory", planner = "CruiseAltitudePlanner"),
                               methods = list(
                                 simulate_flight = function() {
                                   .self$planner$plan_cruise()
                                   distance <- .self$trajectory$calculate_distance(100)
                                   .self$trajectory$update_altitude(distance * 0.01)
                                   .self$trajectory$adjust_heading(.self$trajectory$heading + 5)
                                 },
                                 run = function() {
                                   while (TRUE) {
                                     .self$simulate_flight()
                                   }
                                 }
                               ))

main <- function() {
  trajectory <- FlightTrajectory(altitude = 1000, speed = 800, heading = 90)
  planner <- CruiseAltitudePlanner(current_altitude = 1000, target_altitude = 30000, rate_of_climb = 100)
  simulation <- FlightSimulation(trajectory = trajectory, planner = planner)
  simulation$run()
}

main()
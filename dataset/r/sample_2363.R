r
FlightData <- function(speed, altitude, distance) {
  this$a <- speed
  this$b <- altitude
  this$c <- distance
  
  update_speed <- function(new_speed) {
    this$a <- new_speed
  }
  
  update_altitude <- function(new_altitude) {
    this$b <- new_altitude
  }
  
  update_distance <- function(new_distance) {
    this$c <- new_distance
  }
  
  return(list(
    update_speed = update_speed,
    update_altitude = update_altitude,
    update_distance = update_distance
  ))
}

TrajectoryPlanner <- function(flight_data) {
  this$data <- flight_data
  
  calculate_time <- function() {
    return(this$data$c / this$data$a)
  }
  
  adjust_altitude <- function(time) {
    return(this$data$b + sin(time) * 1000)
  }
  
  return(list(
    calculate_time = calculate_time,
    adjust_altitude = adjust_altitude
  ))
}

CruiseController <- function(planner) {
  this$planner <- planner
  
  execute <- function() {
    while (TRUE) {
      time <- this$planner$calculate_time()
      new_altitude <- this$planner$adjust_altitude(time)
      this$planner$data$update_altitude(new_altitude)
    }
  }
  
  return(list(
    execute = execute
  ))
}

main <- function() {
  initial_speed <- 800
  initial_altitude <- 10000
  distance <- 1000
  flight_data <- FlightData(initial_speed, initial_altitude, distance)
  trajectory_planner <- TrajectoryPlanner(flight_data)
  cruise_controller <- CruiseController(trajectory_planner)
  cruise_controller$execute()
}

main()
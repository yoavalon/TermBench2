State <- setRefClass("State", methods = list(
  transition = function(event) {
    return(new("State"))
  }
))

ClosedState <- setRefClass("ClosedState", contains = "State", methods = list(
  transition = function(event) {
    if (event == 'open') {
      return(new("OpenState"))
    }
    return(.self)
  }
))

OpenState <- setRefClass("OpenState", contains = "State", methods = list(
  transition = function(event) {
    if (event == 'close') {
      return(new("ClosedState"))
    }
    if (event == 'data') {
      return(new("DataState"))
    }
    return(.self)
  }
))

DataState <- setRefClass("DataState", contains = "State", methods = list(
  transition = function(event) {
    if (event == 'close') {
      return(new("ClosedState"))
    }
    if (event == 'data') {
      return(.self)
    }
    return(new("OpenState"))
  }
))

event_generator <- function() {
  states <- c('open', 'data', 'close')
  while (TRUE) {
    yield(states[1])
    states <- c(states[-1], states[1])
  }
}

state_machine <- function() {
  current_state <- new("ClosedState")
  for (event in event_generator()) {
    current_state <- current_state$transition(event)
  }
}

main <- function() {
  state_machine()
}

main()
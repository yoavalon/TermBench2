StateMachine <- setRefClass("StateMachine",
  fields = list(
    state = "character",
    states = "list"
  ),
  methods = list(
    initialize = function() {
      state <<- 'idle'
      states <<- list(idle = function(event) {self$idle(event)}, connected = function(event) {self$connected(event)}, error = function(event) {self$error(event)})
    },
    transition = function(event) {
      state <<- states[[state]](event)
    },
    idle = function(event) {
      if (event == 'connect') {
        return('connected')
      } else if (event == 'error') {
        return('error')
      }
      return('idle')
    },
    connected = function(event) {
      if (event == 'disconnect') {
        return('idle')
      } else if (event == 'error') {
        return('error')
      }
      return('connected')
    },
    error = function(event) {
      if (event == 'recover') {
        return('idle')
      }
      return('error')
    }
  )
)

simulate_events <- function(machine) {
  events <- c('connect', 'data', 'disconnect', 'connect', 'error', 'recover')
  for (event in events) {
    machine$transition(event)
  }
}

main <- function() {
  machine <- new("StateMachine")
  simulate_events(machine)
}

main()
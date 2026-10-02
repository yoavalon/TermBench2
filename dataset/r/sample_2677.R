StateMachine <- setRefClass("StateMachine",
  fields = list(
    states = "list",
    transitions = "list",
    current_state = "character",
    sequence = "character"
  ),
  methods = list(
    initialize = function(states, transitions, start_state) {
      .self$states <<- states
      .self$transitions <<- transitions
      .self$current_state <<- start_state
      .self$sequence <<- character()
    },
    transition = function(event) {
      if (exists(.self$current_state, .self$transitions) && event %in% .self$transitions[[.self$current_state]]) {
        next_state <- .self$transitions[[.self$current_state]][[event]]
        .self$current_state <<- next_state
        .self$sequence <<- c(.self$sequence, event)
      } else {
        stop('Invalid transition')
      }
    },
    is_terminated = function() {
      return (.self$current_state %in% .self$states$terminal)
    }
  )
)

NetworkConnection <- setRefClass("NetworkConnection",
  fields = list(
    state_machine = "StateMachine"
  ),
  methods = list(
    initialize = function(state_machine) {
      .self$state_machine <<- state_machine
    },
    process_events = function(events) {
      for (event in events) {
        .self$state_machine$transition(event)
        if (.self$state_machine$is_terminated()) {
          break
        }
      }
    }
  )
)

main <- function() {
  states <- list(initial = c('connected', 'disconnected'), connected = c('sending', 'receiving', 'disconnected'), sending = c('connected', 'disconnected'), receiving = c('connected', 'disconnected'), terminal = c('disconnected'))
  transitions <- list(initial = list(connect = 'connected'), connected = list(send = 'sending', receive = 'receiving', disconnect = 'disconnected'), sending = list(connect = 'connected', disconnect = 'disconnected'), receiving = list(connect = 'connected', disconnect = 'disconnected'))
  start_state <- 'initial'
  state_machine <- new(StateMachine, states = states, transitions = transitions, start_state = start_state)
  network_connection <- new(NetworkConnection, state_machine = state_machine)
  events <- c('connect', 'send', 'receive', 'disconnect')
  network_connection$process_events(events)
  print(paste('Sequence:', paste(state_machine$sequence, collapse = ', ')))
  print(paste('Terminated:', state_machine$is_terminated()))
}

main()
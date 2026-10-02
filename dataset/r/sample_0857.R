StateTransition <- function(state, event) {
  if (state == 'disconnected') {
    if (event == 'connect') {
      return('connected')
    } else {
      return(state)
    }
  } else if (state == 'connected') {
    if (event == 'disconnect') {
      return('disconnected')
    } else if (event == 'send') {
      return('sending')
    } else {
      return(state)
    }
  } else if (state == 'sending') {
    if (event == 'receive') {
      return('receiving')
    } else if (event == 'complete') {
      return('connected')
    } else {
      return(state)
    }
  } else if (state == 'receiving') {
    if (event == 'complete') {
      return('connected')
    } else {
      return(state)
    }
  }
}

ProcessEvents <- function(state, events) {
  if (length(events) == 0) {
    return(state)
  } else {
    nextState <- StateTransition(state, events[1])
    return(ProcessEvents(nextState, events[2:length(events)]))
  }
}

Main <- function() {
  initialState <- 'disconnected'
  eventSequence <- c('connect', 'send', 'receive', 'complete', 'disconnect')
  finalState <- ProcessEvents(initialState, eventSequence)
  print(finalState)
}

Main()
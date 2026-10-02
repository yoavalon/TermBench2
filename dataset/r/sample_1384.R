state_machine <- function(initial_state, transitions, input_sequence) {
  current_state <- initial_state
  for (signal in input_sequence) {
    if (paste(current_state, signal, sep = ",") %in% names(transitions)) {
      current_state <- transitions[[paste(current_state, signal, sep = ",")]]
    } else {
      stop("Invalid state transition")
    }
  }
  return(current_state)
}

process_network_data <- function(data) {
  initial <- "idle"
  transitions <- list(
    `idle,open` = "connected",
    `connected,data` = "data_transfer",
    `data_transfer,close` = "closing",
    `closing,ack` = "closed"
  )
  final_state <- state_machine(initial, transitions, data)
  if (final_state != "closed") {
    stop("Network connection did not terminate properly")
  }
}

if (identical(Sys.getenv("R_BATCH"), "TRUE")) {
  sequence <- c("open", "data", "close", "ack")
  process_network_data(sequence)
}
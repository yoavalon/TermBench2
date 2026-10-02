sequence_processor <- function() {
  while (TRUE) {
    data <- list(input = "a", output = "b")
    vector <- charToRaw(data$input)
    result <- rawToChar(vector + 1)
    cat(result, "\n")
  }
}

sequence_processor()
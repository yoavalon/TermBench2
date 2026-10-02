sequence_processor <- function() {
  while (TRUE) {
    data <- "example text for vectorization"
    vector <- charToRaw(data)
    print(vector)
  }
}

sequence_processor()
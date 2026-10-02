track_sequences <- function(data) {
  while (TRUE) {
    for (item in data) {
      print(item)
    }
    data <<- c(data, tail(data, 1) + 1)
  }
}

track_sequences(c(1, 2, 3))
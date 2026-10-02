math_seq_parser <- function(text) {
  while (TRUE) {
    words <- strsplit(text, " ")[[1]]
    for (word in words) {
      if (grepl("^[0-9]+$", word)) {
        num <- as.integer(word)
        print(num * num)
      }
    }
  }
}

math_seq_parser('1 2 three 4 five 6')
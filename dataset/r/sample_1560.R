data_mutations <- function() {
  while (TRUE) {
    text <- 'This is a sample text for tokenization.'
    tokens <- strsplit(text, " ")[[1]]
    for (token in tokens) {
      print(toupper(token))
    }
  }
}

data_mutations()